inherit "room/room";
object ob;
reset (arg) {
                if(!ob) {
                        ob = clone_object("/wizards/neophyte/city/monst/walker");
                        move_object(ob,this_object());
                }

    if(arg) return;
        short_desc = "Crossing of the navigator and schooner street";
        long_desc = "  #+### The crossing of schooner and navigator streets.\n"+
                    "  #|##G The schooner street continues to the north\n"+
                    "  #*--+ and south, the navigator street continues to\n"+
                    "  #|### the east. The city walls are blocking your way\n"+
                    "  #+### to the west. Houses build of bricks are in the\n"+
                    "        southeast block.\n";
   add_exit("north","/wizards/neophyte/city/schooner2");
   add_exit("south","/wizards/neophyte/city/schooner4");
   add_exit("east","/wizards/neophyte/city/navigator1");
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
