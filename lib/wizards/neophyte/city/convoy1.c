inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Convoy street";

        long_desc = "+--+--+\n"+
                    "###|### The convoy street continues towards south and north.\n"+
                    "###*#   The city walls are surrounding the streets and whole\n"+
                    "P##|#   city. A small wooden houses are built next to each\n"+
                    "+--+#   another on the streets. The houses are located on the\n"+
                    "        blocks, which are dividing the city.\n";

    add_exit("north","/wizards/neophyte/city/amber3");
    add_exit("south","/wizards/neophyte/city/convoy2");
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
