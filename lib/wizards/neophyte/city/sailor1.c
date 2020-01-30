inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the sailor and barrel street";
        long_desc = "####### You are on the crossing of the barrel and sailor\n"+
                    "+--*--+ streets. Towards southwest can be seen the graveyard\n"+
                    "###|### of the city. An unpleasant smell of rotten bodies\n"+
                    "###+### floats from there. Through the high fence, which is\n"+
                    "        surrounding the graveyard, can be seen tombstones.\n";
   add_exit("south","/wizards/neophyte/city/sailor2");
   add_exit("west","/wizards/neophyte/city/barrel1");
   add_exit("east","/wizards/neophyte/city/barrel2");
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
