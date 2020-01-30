inherit "room/room";
reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/city51.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city49.c");

  short_desc = "You are walking on a street";
    long_desc = "You are walking on a street, behind you there is a\n"+
              "crossing that leads to three different directions. Somewhat ahead,\n"+
              "you see two shops. A big building is standing near you in southwest.\n"+
              "Far south you can see a huge mansion rising towards the sky\n"+
              "and you can also see the roof of the mayor's house in east.\n";


        items = allocate(10);
        items[0] = "crossing";
        items[1] = "There is a crossing in south leading to several places";
        items[2] = "shops";
        items[3] = "You can see two shops in north";
        items[4] = "building";
        items[5] = "A big building is standing in southwest";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky in south";
        items[8] = "roof";
        items[9] = "Far away in east you can see the roof of mayor's house";

}
