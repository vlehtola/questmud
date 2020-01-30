inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the navigator and rudder street";
        long_desc = "###+#   At the crossing of navigator and rudder streets.\n"+
                    "T##|### The navigator street continues to the west and\n"+
                    "+--*--+ and east, rudder street goes to the north and\n"+
                    "###|### south. The houses made of bricks are built next\n"+
                    "###+### to the navigator street, in the blocks.\n";
   add_exit("north","/wizards/neophyte/city/rudder2");
   add_exit("south","/wizards/neophyte/city/rudder4");
   add_exit("west","/wizards/neophyte/city/navigator2");
   add_exit("east","/wizards/neophyte/city/navigator3");
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
