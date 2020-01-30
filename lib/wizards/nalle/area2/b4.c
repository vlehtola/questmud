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

TWO_EXIT("wizards/nalle/area2/b3","west",
          "wizards/nalle/area2/a1","east",
"Avenue des Innocents (4th block)",
"You are standing on an old cobblestone road. There are signs\n" +
"indicating it is called the Avenue des Innocents. It continues to\n" +
"the west and to the east. To your east you notice a crossing of two\n" +
"roads. The air is still, and no signs of life are apparent.\n",3)
