inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city19.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city17.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing in the east that leads to the main road of\n"+
              "Gnael. A huge mansion is rising towards the\n"+
              "sky in the south and there is a small garden behind\n"+
              "strong looking iron bars in the southwest. Voices of the city\n"+
              "are echoing from the walls, but the city looks very\n"+
              "peaceful and calm.\n";

        items = allocate(8);
        items[0] = "crossing";
        items[1] = "There is a small crossing in west that leads to several directions";
        items[2] = "mansion";
        items[3] = "A huge mansion is rising towards the sky nearby";
        items[4] = "garden";
        items[5] = "A very beautiful garden can be seen behind the iron bars in south";
        items[6] = "bars";
        items[7] = "A very strong looking iron bars are protecting the garden";
        
}
