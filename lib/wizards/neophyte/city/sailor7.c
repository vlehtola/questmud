inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the sailor and amber streets";
        long_desc = "  #+### You are walking on the crossing of the sailor\n"+
                    "  #|#Ge and amber streets. The city was established by\n"+
                    "  #*--+ four pirates, who grounded their ship and drived\n"+
                    "  ##### ashore in this very island. After that, when years\n"+
                    "        has gone by, more and more people have come in\n"+
                    "        here and settled down. The amber street is also\n"+
                    "        known as 'Market Street'.\n";
   add_exit("north","/wizards/neophyte/city/sailor6");
   add_exit("east","/wizards/neophyte/city/amber1");
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
