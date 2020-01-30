inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city21.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city19.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing in the west that leads to several different\n"+
              "directions. A huge mansion is rising towards the\n"+
              "sky in the south and there is a small garden behind\n"+
              "strong looking iron bars in the southwest. Voices of the city\n"+
              "are echoing from the walls, but the city looks very\n"+
              "peaceful and calm.\n";

        items = allocate(8);
        items[0] = "crossing";
        items[1] = "There is a small crossing the in west that leads to several directions";
        items[2] = "mansion";
        items[3] = "A huge mansion is rising towards the sky nearby";
        items[4] = "garden";
        items[5] = "Very beautiful garden can be seen behind the iron bars in the southwest";
        items[6] = "bars";
        items[7] = "Very strong looking iron bars are protecting the garden";
        
}
