inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Rudder street";
        long_desc = "+--+--+ At the rudder street, which runs to the north\n"+
                    "###|### and south. The rudder street divides the city\n"+
                    "###*### in two halves. A small wooden houses are built\n"+
                    "e##|#We next to each another, in the blocks of the city.\n"+
                    "+--+--+ Some of the houses are dilapidated.\n";
   add_exit("north","/wizards/neophyte/city/rudder5");
   add_exit("south","/wizards/neophyte/city/rudder7");
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
