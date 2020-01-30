inherit "room/room";

reset(arg) 
   {
        add_exit("northeast", "/wizards/nipa/areat/torni/huoneet/hallway10.c");
        add_exit("west", "/wizards/nipa/areat/torni/huoneet/lounge.c");

   short_desc = "Eastside archway.";
   long_desc = ("Wide archway leading around the tower's first floor.\n"+
               "Dozens of floating candles light the archway beautifully\n"+
               "all the five meter way to the ceiling.\n");

        items = allocate(2);
        items[0] = "candles";
        items[1] = "Brightly glowing white candles float all around the archway.";
}
