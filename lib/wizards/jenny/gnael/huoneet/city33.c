inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city34.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city31_cs.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing in west that leads into the northwest\n"+
              "part of Gnael. Somewhat ahead, you see the central\n"+
              "square and the western gate is located a bit west from\n"+
              "here. There are some houses in south and a huge\n"+
              "mansion is rising to the skies nearby.\n";

        items = allocate(8);
        items[0] = "central square";
        items[1] = "Central square is located far east from here";
        items[2] = "gate";
        items[3] = "A big gate is located bit west from here";
        items[4] = "houses";
        items[5] = "There are some houses located in south";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky nearby";

}
