inherit "room/room";

reset(arg) 
   {
        add_exit("west", "/wizards/nipa/areat/torni/huoneet/lib7.c");
        add_exit("east", "/wizards/nipa/areat/torni/huoneet/lib9.c");
        add_exit("north", "/wizards/nipa/areat/torni/huoneet/stairs1.c");
        add_exit("south", "/wizards/nipa/areat/torni/huoneet/lounge.c");

   short_desc = "Main libray.";
   long_desc = "You have arrived to the heart of the tower the main library.\n"+
               "Mainly the library consists of huge oak shelves and tables with chairs\n"+
               "all the shelves are placed on each corner of the room and are sorted\n"+
               "by categories. Tables are places close to shelves and most of the chairs\n"+
               "are taken by mages reading and inspecting the literatures. The whole room is\n"+
               "lit by same floating candles you see everywhere you go in the tower.\n"+
               "On the center of the room is a pillar of magenta light and something inside it.\n";


        items = allocate(4);
        items[0] = "candles";
        items[1] = "Brightly glowing white candles float all around the main library.";
        items[2] = "shelves";
        items[3] = "Huge oak shelves containing numerous books and scrolls about magic.";


}
