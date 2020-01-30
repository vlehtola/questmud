inherit "room/room";
object ob;
reset (arg) {
                if(!ob) {
                        ob = clone_object("/wizards/neophyte/city/monst/walker");
                        move_object(ob,this_object());
                }
    if(arg) return;
        short_desc = "Crossing of the anchor and schooner street";
        long_desc = "  #+### You are on the crossing of the schooner and\n"+
                    "  #|##H anchor streets. The schooner street continues\n"+
                    "  #*--+ to the north and barrel street to the east.\n"+
                    "  ##### The street is silent and empty. The city walls\n"+
                    "        are blocking the way to the south and west.\n";

   add_exit("north","/wizards/neophyte/city/schooner4");
   add_exit("east","/wizards/neophyte/city/anchor1");
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
