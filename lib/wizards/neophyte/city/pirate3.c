inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the pirate and anchor street";
        long_desc = "###|# At the crossing of the pirate and anchor\n"+
                    "###|# streets. The pirate street continues to the\n"+
                    "+--*# north and south, the anchor street goes to\n"+
                    "###|# the west. The city walls are blocking the way\n"+
                    "###+# to the east. The pirate block ends in here.\n";

   add_exit("north","/wizards/neophyte/city/pirate2");
   add_exit("south","/wizards/neophyte/city/pirate4");
   add_exit("west","/wizards/neophyte/city/anchor4");
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
