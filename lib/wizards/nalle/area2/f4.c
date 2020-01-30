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

THREE_EXIT("wizards/nalle/area2/f5","north",
          "wizards/nalle/area2/workshop","west",
          "wizards/nalle/area2/b7","south",
"Eastern wastelands",
"You are on the eastern extremity of the city. It is very silent\n" +
"here and what you thought was a road, looking from further away,\n" +
"is just trampled dirt and rubble. There is a house to your west.\n",3)

