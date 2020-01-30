inherit "room/room";

reset(arg) {

        add_exit("north","/wizards/jenny/gnael/huoneet/mayor11.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/mayor14.c");

    short_desc = "Inside the mayor's house";
    long_desc = "You have arrived into the second floor of the\n"+
              "mayor's house. Everywhere you look you see busy\n"+
              "looking bureaucrats running on errands. The floor\n"+
              "is made of parquet and it looks very expensive and\n"+
              "new. Some candles are burning on the walls laying\n"+
              "light to floor nicely.\n";

  set_not_out(1);
  set_light(3);

        items = allocate(6);
        items[0] = "bureaucrats";
        items[1] = "Busy looking bureaucrats are running on errands all the time";
        items[2] = "parquet";
        items[3] = "Very expensive looking parquet is covering the whole floor";
        items[4] = "candles";
        items[5] = "The candles are giving light to the room";

}
