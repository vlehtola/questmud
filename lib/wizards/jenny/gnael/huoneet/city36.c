inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city2.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city35.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing in west that leads into the southwest\n"+
              "part of Gnael. Somewhat ahead, you see the central\n"+
              "square and western gate is located a bit west from\n"+
              "here. There are some houses in south, a big building\n"+
              "in north and a huge mansion is rising to the skies\n"+
              "nearby. Two dogs are barking to you near, but they\n"+
              "don't seem to be hostile.\n";

        items = allocate(12);
        items[0] = "central square";
        items[1] = "Central square is located far east from here";
        items[2] = "gate";
        items[3] = "A big gate is located bit west from here";
        items[4] = "houses";
        items[5] = "There are some houses located in south";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky nearby";
        items[8] = "dogs";
        items[9] = "Two fluffy looking dogs are barking to strangers";
        items[10] = "building";
        items[11] = "A big building is located in north";

}
