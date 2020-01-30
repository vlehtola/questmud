inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the amber and convoy streets";

        long_desc = "######+\n"+
                    "We#Ar#| You are standing on the crossing of the amber\n"+
                    "+--*--+ and convoy streets. The amber streets continues\n"+
                    "###|### to the west and east, convoy streets goes to the\n"+
                    "###+#   south. There are lots of sailors and travellers\n"+
                    "        browsing the shops. To the north is the armour shop.\n"+
                    "        The amber street is also known as 'Market Street'.\n";
   add_exit("west","/wizards/neophyte/city/amber2");
   add_exit("east","/wizards/neophyte/city/pirate5");
   add_exit("south","/wizards/neophyte/city/convoy1");
   add_exit("north","armour_shop");
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
