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

THREE_EXIT("wizards/nalle/area2/f6","north",
          "wizards/nalle/area2/c6","west",
          "wizards/nalle/area2/f4","south",
"Eastern wastelands",
"You are on the eastern extremity of the city. It is very silent\n" +
"here and what you thought was a road, looking from further away,\n" +
"is just trampled dirt and rubble. A road leads to the west.\n",3)
