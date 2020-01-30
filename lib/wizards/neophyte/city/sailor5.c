inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the sailor and anchor streets";
        long_desc = "###+### At the crossing of the sailor and anchor streets.\n"+
                    "H##|### The city is growing all the time, more travellers\n"+
                    "+--*--+ are coming in this secluded city. Nowadays there\n"+
                    "###|### are guards guarding the city gate, trying to prevent\n"+
                    "  #+#   the migration. The wooden houses are built next to\n"+
                    "        the streets on the blocks.\n";

   add_exit("north","/wizards/neophyte/city/sailor4");
   add_exit("south","/wizards/neophyte/city/sailor6");
   add_exit("west","/wizards/neophyte/city/anchor1");
   add_exit("east","/wizards/neophyte/city/anchor2");
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
