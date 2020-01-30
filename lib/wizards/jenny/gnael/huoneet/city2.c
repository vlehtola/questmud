inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city1.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city36.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city3.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing that leads to the southwest part of Gnael.\n"+
              "Somewhat ahead you see the central square and\n"+
              "the western gate is located a bit west. There are\n"+
              "some houses in south and a mansion is rising\n"+
              "to the skies nearby. Two dogs are barking\n"+
              "to you near, but they don't seem to be hostile.\n";

        items = allocate(10);
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
}
