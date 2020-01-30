inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Schooner street";
        long_desc = "  #+--+ The schooner street continues to the north\n"+
                    "  #|### and south. The city is divided in blocks by\n"+
                    "  #*### the streets, which are running from various\n"+
                    "  #|##H directions. The surrounding city walls are\n"+
                    "  #+--+ raising in west just next to the street.\n"+
                    "        The huge wooden house is dominating the whole\n"+
                    "        block in east.\n";
   add_exit("north","/wizards/neophyte/city/schooner3");
   add_exit("south","/wizards/neophyte/city/schooner5");
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
