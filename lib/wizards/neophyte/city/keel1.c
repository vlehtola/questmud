inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the keel and rudder streets";
        long_desc = "|#####| You are walking on the keel street, which continues\n"+
                    "|##P##| to west and east from here. There are streets running\n"+
                    "+--*--+ through the city, dividing the city to small blocks.\n"+
                    "###|### The city walls are built around the city. Small wooden\n"+
                    "  #+#   houses are build next to each other near the streets.\n";
    add_exit("south","/wizards/neophyte/city/entrance");
    add_exit("north","/wizards/neophyte/city/gpost");
    add_exit("west","/wizards/neophyte/city/rudder9");
    add_exit("east","/wizards/neophyte/city/convoy2");
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
