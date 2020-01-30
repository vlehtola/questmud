inherit "/wizards/gynter/daemons/trap";

start() {
  alias = "box";
  name = "box";
  short_desc = "A small wodden box";
  long_desc = "The box is made out of twisted parts of wood attached to eachother\n"+
              "by some kind of material you have never seen before. From the box a big log extends\n"+
              "high into the air and as you walk around the box the arm wavers dangerly.\n"+
              "In the middle of the box there is one lever and one switch.\n"+
              "Suddenly you notice thousands of sharp blades on the log... you wouldn't have seen\n"+
              "them if you hadn't fallen on a rock. This trap must be leathal.\n";

  damage = 1000;
  active = 1;
execute_mess = "As you trigger the trap you see the arm of the trap starting to move.\n"+
               "It only takes a split second but for you it is like an eternety as you watch the\n"+
               "blades closing in on you and with a loud thud it impacts in your chest rending you\n"+
               "and punktures every vital organ in your body. You last thought before you die is :\n"+
              "How will I now drink water?.\n";
  deactiv_mess = "As you turn the switch to the left, the machine starts to move. Just as you think\n"+
                "you will die the arm of the machine is pulled into the trap and you realise that you are safe.\n"+
               "               ..for now..\n";
  activ_mess = "As you turn the switch you start to realise the immense\n"+
            "error you have made, because an arm is beguinning to extend itself from\n"+
            "the small box... and now it's a LEATHAL trap!<tm> What will you do now?\n";

        items = allocate(4);
        items[0] = "lever";
items[1] = "There is a small lever on the side of the trap... maybe you should 'pull' it?";
        items[2] = "switch";
        items[3] = "There is a BIG switch in the front of the machine... maybe you should 'turn' it?";

}

init() {
  add_action("pulling", "pull");
  add_action("turning", "turn");
}

pulling(str) {
 if(str != "lever") {
    write("Pull what?!?\n");
    return 1;
  }
  execute();
}

turning(str) {
  if(str != "switch") {
    write("Turn what?!?\n");
    return 1;
  }
  if(query_active()) {
    deactivate();
  } else {
    activate();
  }
}
