inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "A small pier on the mainland";
    long_desc = "A small pier is built on the mainland. The pier is made of wood, therefore it's\n"+ 
                "a bit brittle. An island is towards north about hundred meters from here. You can\n"+
                "see a half-sunken ferry next to the pier on the island. The island can be reached\n"+
                "only by swimming. Ten burning torches, five on both sides of the pier, are placed\n"+
                "in the holes which are in the pier. The flames dances on the torches as the hard\n"+
                "and cold wind blows from the sea. Two old ropes and lying on the pier. An old life\n"+
                "buoy is hanging from the board.\n";

   items = allocate(6);
   items[0] = "torches";
   items[1] = "Ten burning torches are placed in holes which are in the pier.";
   items[2] = "ropes";
   items[3] = "Two old ropes are lying on the pier.";
   items[4] = "buoy";
   items[5] = "And old life buoy is hanging from the board which is standing in the end of the pier.";

    add_exit("east", "out: ");
    add_exit("west", "out: ");
    add_exit("south", "out: ");
    add_exit("north", "out: ");
    set_light(3);
}

