inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Amber street";
        long_desc = "+#####+ You are on the amber street, which continues to\n"+
                    "|#Ge##| the west and east. There are lots of sailors and\n"+
                    "+--*--+ pirates browsing the shops. It's quite hullabaloo\n"+
                    "######| in daytime in here. The city walls are blocking\n"+
                    "        the way to the south. To the north is the general\n"+
                    "        shop. This street is also known as 'Market Street'.\n";

   add_exit("west","/wizards/neophyte/city/sailor7");
   add_exit("east","/wizards/neophyte/city/rudder7");
   add_exit("north","/wizards/neophyte/city/general_shop");
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
