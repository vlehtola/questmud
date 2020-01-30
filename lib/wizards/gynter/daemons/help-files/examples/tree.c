inherit "/wizards/gynter/daemons/trap";

start() {
  alias = "gnarled tree";
  name = "tree";
  short_desc = "A huge gnarled tree";
  long_desc = "This is one of the most magestic tree's you have ever seen.\n"+
              "If you didn't know better you could think that this tree is\n"+
              "the oldest tree in the world.. but.. what is that one the side\n"+
              "a small button of some kind. And one of the roots seem to be loose..\n"+
              "Have someone hurt this tree? .. Wonder what that button will do?\n";
  damage = 2000;
  active = 1;
  execute_mess = "As you push the button the tree starts moving and it starts\n"+
                 "to glow with a blue hue. The hue increases until it is almost\n"+
                 "blinding, then the light just goes black. When your eyes have\n"+
                 "focused once again you see the tree starting to embrace you\n"+
                 "with two HUGE branches. When the branches close in around you, it\n"+
                 "hurts in the chest at first but as the tree continues to squeece\n"+
                 "your last breath out of you everything goes black and your last\n"+
                 "thought is:\n"+
                 "Praise to Gynter the trap<tm> maker.\n";
  deactiv_mess = "As you take hold of the loose root you see the tree wailing in pain\n"+
                 "and you start to understand the nature of this tree. It is the ancient\n"+
                 "Malgoo-tree.. but it's harmless.. .. for now.\n";
  activ_mess = "As you pull the root you see the tree wailing in pain and\n"+
               "the ancient tree howls to the moon with no voice. But you understand\n"+
               "the words..  a promise of death..\n";

        items = allocate(4);
        items[0] = "button";
        items[1] = "There is a button on the side of the tree...\n"+
                   "maybe you should 'push' it?";
        items[2] = "root";
        items[3] = "There is a loose root at the ground... but you suspect\n"+
                   "it is connected to the tree in some way...\n"+
                   "maybe you should 'pull' it?";
}

init() {
  add_action("pulling", "pull");
  add_action("pushing", "push");
}

pushing(str) {
  if(str != "button") {
    write("Push what?\n");
    return 1;
  }
  execute();
}

pulling(str) {
  if(str != "root") {
    write("Push what?\n");
    return 1;
  }
  if(query_active()) {
    deactivate();
    return 1;
  } else {
    activate();
    return 1;
  }
}
