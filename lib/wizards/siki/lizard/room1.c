inherit "room/room";

reset(arg) {


  add_exit("north","/wizards/siki/lizard/room2");
  add_exit("east","/wizards/siki/lizard/room3");
  add_exit("south","/wizards/siki/lizard/room4");
  add_exit("west","/wizards/siki/lizard/room5");
  add_exit("leave","/wizards/siki/lizard/entrance");

  short_desc = "A small village";
  long_desc = "A small quiet village. The ground is tough and damp. There\n"+
              "are no trees or anything else growing anywhere near.\n";
}

