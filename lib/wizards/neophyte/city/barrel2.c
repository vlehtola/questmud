inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Barrel street";
        long_desc = "####### In the middle of the barrel street. The street\n"+
                    "+--*--+ is running towards west and east. Your way to the\n"+
                    "|#####| north is blocked by the city walls. A wooden houses\n"+
                    "+#####+ are built in the blocks. The blocks are formed by\n"+
                    "        the streets, which are running from various directions.\n";
   add_exit("west","/wizards/neophyte/city/sailor1");
   add_exit("east","/wizards/neophyte/city/rudder1");
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
