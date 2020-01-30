#include "room.h"

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/nalle/area2/map");
   return 1;
}

TWO_EXIT("wizards/nalle/area2/f1","north",
          "wizards/nalle/area2/b2","east",
"Avenue des Innocents (1st block)",
"You are standing on an old cobblestone road. There are signs \n" +
"indicating it is called the Avenue des Innocents. It continues to \n" +
"the to the east. There are badly maintained grounds to the north \n" +
"and piles of rubble, rock and the valley wall to the west.\n",3)
