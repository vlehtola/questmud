inherit "room/room";
object ob;
reset (arg) {
	if(!ob) {
		ob = clone_object("/wizards/neophyte/city/monst/walker");
		move_object(ob,this_object());
	}
    if(arg) return;
        short_desc = "Crossing of the rudder and keel street";
        long_desc = "  #|### This is the crossing of the rudder and keel street,\n"+
                    "  #|##P rudder street runs towards north and keel street towards\n"+
                    "  #*--+ east. The streets of the city are dividing the city to a\n"+
                    "  ####| small blocks. The blocks consist of a small wooden houses,\n"+
                    "     #+ which are build next to each another near the streets. The\n"+
                    "        city walls are marking the limits of the city.\n";
   add_exit("north","/wizards/neophyte/city/rudder8");
   add_exit("east","/wizards/neophyte/city/keel1");
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
