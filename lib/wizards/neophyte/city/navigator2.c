inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Navigator street";
        long_desc = "+#####+ This is the navigator street. The street is\n"+
                    "|##T##| very clean and in good condition. The houses\n"+
                    "+--*--+ made of bricks are built next to the street.\n"+
                    "|#####| The navigator street is running towards east\n"+
                    "+#####+ and west. This is the fashionable street,\n"+
                    "        where all the rich people live. To the north\n"+
                    "        is entrance to the temple.\n";
   add_exit("north","/wizards/neophyte/city/temple/temple1");
   add_exit("west","/wizards/neophyte/city/sailor3");
   add_exit("east","/wizards/neophyte/city/rudder3");
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
