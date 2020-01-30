inherit "room/room";

reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/city3.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city21.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city5.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing ahead of you that leads to several\n"+
              "different directions. There is a cosy looking house\n"+
              "in the north and a huge mansion in the east. A small\n"+
              "garden can be seen behind iron bars near the mansion.\n"+
              "Voices of the city are echoing from the walls, but the city\n"+
              "looks very peaceful and calm.\n";

        items = allocate(8);
        items[0] = "crossing";
        items[1] = "There is a small crossing that leads to several directions";
        items[2] = "house";
        items[3] = "A cosy looking house is located north";
        items[4] = "mansion";
        items[5] = "A huge mansion is rising towards the sky nearby";
        items[6] = "garden";
        items[7] = "Very beautiful garden can be seen behind the iron bars nearby";
}
