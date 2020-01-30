inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Pirate street";
        long_desc =
                    "---+# The pirate street runs towards north and south.\n"+
                    "###|# Next to the street is the city walls on the east\n"+
                    "###*# side and on the west side is the small, wooden\n"+
                    "Ar#|# houses which are inhabited by the pirates. This\n"+
                    "+--+# must be the pirate block.\n";

   add_exit("north","/wizards/neophyte/city/pirate3");
   add_exit("south","/wizards/neophyte/city/pirate5");
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
