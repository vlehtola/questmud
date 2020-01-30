inherit "room/room";
object ob;
reset (arg) {
    if(arg) return;
    if(!ob) {
		ob = clone_object("/wizards/neophyte/city/obj/statue");
		move_object(ob, this_object());
	}
        short_desc = "Crossing of the anchor and rudder street";
        long_desc = "###+### This is the crossing of the anchor and rudder\n"+
                    "###|#In streets. The anchor streets continues to the west\n"+
                    "+--*--+ and east, rudder streets goes to the north and.\n"+
                    "###|### south. There are lots of drunken sailors and\n"+
                    "###+### pirates walking near that inn, which is located\n"+
                    "        in east. This crossing is also known as the\n"+
                    "        'Central Square' of the city.\n";
   add_exit("north","/wizards/neophyte/city/rudder4");
   add_exit("south","/wizards/neophyte/city/rudder6");
   add_exit("west","/wizards/neophyte/city/anchor2");
   add_exit("east","/wizards/neophyte/city/anchor3");
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
