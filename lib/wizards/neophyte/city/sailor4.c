inherit "room/room";
object ob;
reset (arg) {
        if(!ob) {
                ob = clone_object("/wizards/neophyte/city/monst/walker");
                move_object(ob, this_object());
        }

    if(arg) return;
        short_desc = "Sailor street";
        long_desc = "+--+--+ Street after street. You are now on the sailor street.\n"+
                    "###|### The sailor street continues to the north and south. The\n"+
                    "###*### city is overpopulated and more of travellers are coming\n"+
                    "H##|### all the time in here. The street is full of trash and\n"+
                    "        other dirty stuff, which smells quite bad.\n";

   add_exit("north","/wizards/neophyte/city/sailor3");
   add_exit("south","/wizards/neophyte/city/sailor5");
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
