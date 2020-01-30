inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the amber and pirate streets";
        long_desc = "###|# The amber and pirate streets makes a crossing,\n"+
                    "Ar#|# which divides in two direction. The amber street\n"+
                    "+--*# continues to the west and pirate to the north. \n"+
                    "##### There are lots of sailors and travellers browsing\n"+
                    "      the shops. The city walls surrounds the city. The\n"+
                    "      amber street is also known as 'Market Street'.\n";
   add_exit("north","/wizards/neophyte/city/pirate4");
   add_exit("west","/wizards/neophyte/city/amber3");
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
