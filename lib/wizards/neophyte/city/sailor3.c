inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the sailor and navigator street";
        long_desc = "###+### At the crossing of the sailor and navigator\n"+
                    "G##|##T streets. The city is divided in blocks by\n"+
                    "+--*--+ the streets, which are running from various\n"+
                    "###|### directions. There are brick houses built next\n"+
                    "###+### to the streets. The navigator street is the\n"+
                    "        fashionable street.\n";
   add_exit("north","/wizards/neophyte/city/sailor2");
   add_exit("south","/wizards/neophyte/city/sailor4");
   add_exit("west","/wizards/neophyte/city/navigator1");
   add_exit("east","/wizards/neophyte/city/navigator2");
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
