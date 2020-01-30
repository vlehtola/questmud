inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil09");
  add_exit("south", "/wizards/ahma/orc/village/vil08");
  short_desc = "Central part of Ilem street";
  long_desc = "########### The Ilem street continues to north and south. In west can be seen\n" + 
             "#### |  \\ # the town square, but a deep moat is surrounding it. Thick, green\n" + 
              "#### *   `# bushes and some stunted-looking trees line the road in its eastern\n" + 
              "#### |    # side. One branch of a tree has fallen in the roadside. There must\n" + 
              "########### be something special about it because it is fallen down.\n";

  items = allocate(2);
  items[0] = "branch";
  items[1] = "A branch of the stunted-looking tree has fallen in the roadside. Despite that\n" + 
             "the tree looks healthy enough for not loosing its branches yet. As you examine\n" +
             "the branch more carefully you spot some teeth marks near the base of the branch.\n" + 
             "The conclusion is, that the branch has been gnawed of from the tree";
  
  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/woman"), this_object()); mob++; }
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

childdead() {
  mob--;
}