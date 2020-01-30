inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Anchor street";
        long_desc = "+#####+ At the anchor street, which continues to\n"+
                    "|#####| the west and east. This street looks rather\n"+
                    "+--*--+ silent and empty, maybe because sailors and\n"+
                    "|#####| pirates dont like to be in center of things.\n"+
                    "+#####+ The wooden houses built next to the street\n"+
                    "        are dilapidated.\n";
   add_exit("west","/wizards/neophyte/city/sailor5");
   add_exit("east","/wizards/neophyte/city/rudder5");
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
