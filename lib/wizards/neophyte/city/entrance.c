#include "/wizards/neophyte/city/misc/misc.h"
inherit "room/room";
object guard;
reset (arg) {
                       if(!guard) {
                               guard = clone_object(monspath+"guard");
                               move_object(guard, this_object());
}
    if(arg) return;
        short_desc = "Entrance to the city";
        long_desc = "|##P##| You are standing in front of two big iron gates, which are\n"+
                    "+--+--+ unfortunately closed. This is the one and only entrance to\n"+
                    "###|### the city. Through the gates can be seen lots of people\n"+
                    "  #*#   walking in the city streets. The city walls are surrounding\n"+
                    "        the city offering shelter from the weather and enemies.\n";

    add_exit("north","/wizards/neophyte/city/keel1");
    add_exit("south","/wizards/duncan/island/virtual_map: 42 14");

   items = allocate(2);
   items[0] = "gates";
   items[1] = "The iron gates are closed. There can be seen people walking in the streets of the city";
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
