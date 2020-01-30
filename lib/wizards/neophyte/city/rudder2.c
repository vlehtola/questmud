inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Rudder street";
        long_desc = "+--+#   The rudder street is running to the north and\n"+
                    "###|#   south. The rudder street divides the city in\n"+
                    "###*#   two halves. A small wooden houses are built\n"+
                    "T##|### next to each another, in the blocks of the city.\n"+
                    "+--+--+ Some of the houses are dilapidated.\n";
   add_exit("north","/wizards/neophyte/city/rudder1");
   add_exit("south","/wizards/neophyte/city/rudder3");
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
