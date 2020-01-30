inherit "room/room";

reset(arg) { 

        add_exit("up","/wizards/jenny/gnael/huoneet/mansion15.c");
        add_exit("down","/wizards/jenny/gnael/huoneet/mansion17.c");

  short_desc = "In a staircase";
  long_desc = "You are walking in a staircase that leads into the\n"+
              "basement of the mansion. You can't see the bottom yet,\n"+
              "but you can smell a rotten smell coming from downstairs.\n"+
              "There are not many light sources near, but you can still\n"+
              "see the rats running on the floor. You have a bad feeling\n"+
              "about this place.\n";

        items = allocate(4);
        items[0] = "downstairs";
        items[1] = "You can't see that far";
        items[2] = "rats";
        items[3] = "Disgusting looking rats are running on the floor";
}
