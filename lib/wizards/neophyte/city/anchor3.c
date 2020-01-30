inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Anchor street";
        long_desc = "+###### The anchor street continues to the west and\n"+
                    "|#Inn## east, dividing the city in two halves. In north\n"+
                    "+--*--+ is the entrance to the pub. The pub seems quite\n"+
                    "|###### full of pirates and sailors drinking booze and\n"+
                    "+###### discussing loudly. THe people gather around the\n"+
                    "        island in here, telling stories and latest news.\n";

   add_exit("west","/wizards/neophyte/city/rudder5");
   add_exit("east","/wizards/neophyte/city/anchor4");
   add_exit("north","/wizards/neophyte/city/pub");
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
