inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Schooner street";
        long_desc = "  #+--+ You standing in the middle of the schooner street,\n"+
                    "  #|### which continues to the south and north. The street is\n"+
                    "  #*### totally empty and silent, because of the graveyard.\n"+
                    "  #|##G The graveyard is in east block, but you can't get\n"+
                    "  #+--+ in there, because there's a high fence surrounding\n"+
                    "        it. The city walls are blocking your way to the west.\n";
   add_exit("north","/wizards/neophyte/city/schooner1");
   add_exit("south","/wizards/neophyte/city/schooner3");
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
