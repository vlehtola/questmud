inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the rudder and amber street";
        long_desc = "###+###\n"+
                    "e##|#We You are on the crossing of the rudder and amber\n"+
                    "+--*--+ streets. The rudder street continues to the north\n"+
                    "###|### and south, amber street to the west and east.\n"+
                    "  #+### There are lots of sailors and travellers browsing\n"+
                    "        the shops on the streets. The amber street is also\n"+
                    "        known as 'Market Street'.\n";
   add_exit("north","/wizards/neophyte/city/rudder6");
   add_exit("south","/wizards/neophyte/city/rudder8");
   add_exit("west","/wizards/neophyte/city/amber1");
   add_exit("east","/wizards/neophyte/city/amber2");
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
