inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the pirate and navigator street";
        long_desc = "\n"+
                    "##### At the crossing of the pirate and navigator\n"+
                    "+--*# streets. The pirate street goes to the south,\n"+
                    "###|# and navigator to the west. The city walls\n"+
                    "###+# are blocking the way to the north and east.\n";
   add_exit("west","/wizards/neophyte/city/navigator4");
   add_exit("south","/wizards/neophyte/city/pirate2");
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
