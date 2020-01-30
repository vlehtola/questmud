inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Navigator street";
        long_desc = "+#      This is the navigator street. The street is\n"+
                    "|###### very clean and in good condition. The houses\n"+
                    "+--*--+ made of bricks are built next to the street.\n"+
                    "|###### The navigator street is running towards east\n"+
                    "+###### and west. This is the fashionable street, \n"+
                    "        where all the rich people live.\n";
   add_exit("west","/wizards/neophyte/city/rudder3");
   add_exit("east","/wizards/neophyte/city/navigator4");
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
