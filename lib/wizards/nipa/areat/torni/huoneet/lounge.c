inherit "room/room";

reset(arg) 
   {
        add_exit("out","/wizards/nipa/areat/torni/huoneet/entrance.c");
         add_exit("north", "/wizards/nipa/areat/torni/huoneet/lib8.c");
        add_exit("east", "/wizards/nipa/areat/torni/huoneet/hallway11.c");
        add_exit("west", "/wizards/nipa/areat/torni/huoneet/hallway1.c");

   short_desc = "Beautifully decorated lounge.";
   long_desc = "You have entered in beautifully decorated lounge.\n"+
               "You can see huge archways leading to east and west.\n"+
               "In front you can see open doorway which seems to lead to library.\n"+
               "By the length of corridor you can see grand statues.\n"+
               "These statues are made of marble and they represent former\n"+
               "archmages of this tower. You feel uneasy as you walk by the\n"+
               "statues, as if they are following your every step. The hallway\n"+
               "is lighted by dozens of candles that float in mid-air.\n";

        items = allocate(4);
        items[0] = "statues";
        items[1] = "You get a feeling that eyes of the statues follow your every move.";
        items[2] = "candles";
        items[3] = "Brightly glowing white candles float all around the lounge.";
}
