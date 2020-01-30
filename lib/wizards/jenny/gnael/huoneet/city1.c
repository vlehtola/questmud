inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/gate1.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city2.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there are\n"+
              "some dogs barking nearby and people are\n"+
              "doing their daily routines. There is a\n"+
              "huge gate leading out of the city in west and\n"+
              "the road is leading east to the central square\n"+
              "and some roads cross to this road also.\n"+
              "There is a nice looking house south from\n"+
              "you and someone is looking out of the window\n"+
              "in the second floor of the house.\n";

 
        items = allocate(8);
        items[0] = "gate";
        items[1] = "A big gate is located bit west from here";
        items[2] = "house";
        items[3] = "A cosy looking house is located south from you";
        items[4] = "window";
        items[5] = "some kids are looking out of the window";
        items[6] = "someone";
        items[7] = "some kids are looking out of the window";
}
