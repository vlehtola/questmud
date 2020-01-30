inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Rudder street";
        long_desc = "###|### The rudder street continues towards south and north.\n"+
                    "  #*### The city walls are surrounding the streets and whole\n"+
                    "  #|##P city. A small wooden houses are built next to each\n"+
                    "  #+--+ another on the streets. The houses are located on the\n"+
                    "        blocks, which are dividing the city.\n";

   add_exit("north","/wizards/neophyte/city/rudder7");
   add_exit("south","/wizards/neophyte/city/rudder9");
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
