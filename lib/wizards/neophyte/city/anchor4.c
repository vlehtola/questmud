inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Anchor street";
        long_desc = "######| This is the anchor street, which continues\n"+
                    "Inn###| to the west and east. To the west is lots\n"+
                    "+--*--+ of people, maybe it's because there is a pub.\n"+
                    "######| The small wooden houses are built next to the\n"+
                    "######+ street, which divides the city to the blocks.\n";

   add_exit("west","/wizards/neophyte/city/anchor3");
   add_exit("east","/wizards/neophyte/city/pirate3");
}

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/neophyte/city/map");
   return 1;
}
