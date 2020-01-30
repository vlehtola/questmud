inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Barrel street";
        long_desc = "####### This is the barrel street. It leads to the\n"+
                    "+--*--+ west and east. Towards south can be seen the\n"+
                    "|#####| graveyard of the city. An unpleasant smell of\n"+
                    "|#####| rotten bodies floats in here. Through the high\n"+
                    "        fence, which is surrounding the graveyard, can\n"+
                    "        be seen tombstones and crosses.\n";
   add_exit("west","/wizards/neophyte/city/schooner1");
   add_exit("east","/wizards/neophyte/city/sailor1");
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
