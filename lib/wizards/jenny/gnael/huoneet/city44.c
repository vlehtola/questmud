inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city43.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/city54.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city45.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing in here that leads into the northeast\n"+
              "part of Gnael. Somewhat ahead, you see the central\n"+
              "square and the eastern gate is located a bit east from\n"+
              "here. There are some houses in south and the mayor's\n"+
              "house can be seen in north.\n";

        items = allocate(8);
        items[0] = "central square";
        items[1] = "Central square is located bit west from here";
        items[2] = "gate";
        items[3] = "A big gate leading outside is located bit east from here";
        items[4] = "houses";
        items[5] = "There are some houses located in south";
        items[6] = "house";
        items[7] = "The mayor's house can be seen in north";

}
