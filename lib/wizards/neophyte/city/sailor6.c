inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Sailor street";
        long_desc = "+--+--+ At the sailor street, which divides the city to\n"+
                    "###|### a small blocks. This is the street where the\n"+
                    "  #*### sailors live. The city was established by four\n"+
                    "  #|### pirates, who grounded their ship and drived ashore\n"+
                    "  #+#Ge in this very island. After that, when years has\n"+
                    "        gone by, more and more people have come in here and\n"+
                    "        settled down. Nowadays this city is quite big and\n"+
                    "        self-sufficant.\n";
   add_exit("north","/wizards/neophyte/city/sailor5");
   add_exit("south","/wizards/neophyte/city/sailor7");
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
