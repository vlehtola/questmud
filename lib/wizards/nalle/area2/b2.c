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

TWO_EXIT("wizards/nalle/area2/b1","west",
          "wizards/nalle/area2/b3","east",
"Avenue des Innocents (2nd block)",
"You are standing on an old cobblestone road. There are signs\n" +
"indicating it is called the Avenue des Innocents. It continues to\n" +
"the west and to the east. You notice a gateway leading to the\n" +
"graveyard further to the east, and a crossing to the west.\n",3)
