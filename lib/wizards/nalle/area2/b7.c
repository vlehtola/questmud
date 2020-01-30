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

TWO_EXIT("wizards/nalle/area2/b6","west",
          "wizards/nalle/area2/f4","north",
"Avenue des Innocents (7th block)",
"You are standing on an old cobblestone road. There are signs\n" +
"indicating it is called the Avenue des Innocents. It continues to\n" +
"the west. To your north you notice a different road going \n" +
"north. The air is still, and no signs of life are apparent.\n",3)
