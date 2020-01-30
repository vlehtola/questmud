inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the barrel and rudder street";
        long_desc = "##### You are standing on the crossing of the rudder and\n"+
                    "+--*# barrel streets. The barrel street continues to the\n"+
                    "###|# west and rudder street to the south. The city walls\n"+
                    "###+# are blocking your way to the north and east. A small\n"+
                    "      wooden houses are built next to each another. Some\n"+
                    "      of the houses are dilapidated.\n";
   add_exit("west","/wizards/neophyte/city/barrel2");
   add_exit("south","/wizards/neophyte/city/rudder2");
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
