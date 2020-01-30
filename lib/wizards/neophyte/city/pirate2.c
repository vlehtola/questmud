inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Pirate street";
        long_desc = "+--+# The pirate street runs in two directions, to\n"+
                    "###|# the north and south. The city is divided in\n"+
                    "###*# blocks by the streets, which are running in\n"+
                    "###|# various directions. Next to the street is\n"+
                    "+--+# the block, where the pirates live. That's\n"+
                    "      why this street was named as pirate street.\n";
   add_exit("north","/wizards/neophyte/city/pirate1");
   add_exit("south","/wizards/neophyte/city/pirate3");
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
