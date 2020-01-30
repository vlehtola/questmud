inherit "room/room";
reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/city49.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city47.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing in south that leads into the main road\n"+
              "of Gnael. Somewhat ahead, you see a few shops\n"+
              "and a big building is standing next to you in west.\n"+
              "Far south you can see a huge mansion rising towards\n"+
              "the sky and you can see the roof of the mayor's house\n"+
              "in east.\n";

        items = allocate(10);
        items[0] = "crossing";
        items[1] = "There is a crossing in south leading to several places";
        items[2] = "shops";
        items[3] = "You can see a few shops in north";
        items[4] = "building";
        items[5] = "A big building is standing next to you";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky in south";
        items[8] = "roof";
        items[9] = "Far away in east you can see the roof of mayor's house";

}
