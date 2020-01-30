inherit "room/room";
object ob;
reset (arg) {
        if(!ob) {
                ob = clone_object("/wizards/neophyte/city/monst/walker");
                move_object(ob,this_object());
        }
    if(arg) return;
        short_desc = "Sailor street";
        long_desc = "+--+--+ Street after street. You are now on the sailor street.\n"+
                    "###|### The sailor street continues to the north and south. The\n"+
                    "###*### city is overpopulated and more of travellers are coming\n"+
                    "G##|##T all the time in here. The street is full of trash and\n"+
                    "+--+--+ other dirty stuff. A graveyard is in the west block\n"+
                    "        surrounded by high fence. The smell which is floating\n"+
                    "        in here is mixing of rotten bodies and trash.\n";
   add_exit("north","/wizards/neophyte/city/sailor1");
   add_exit("south","/wizards/neophyte/city/sailor3");
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
