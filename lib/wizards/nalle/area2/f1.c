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

TWO_EXIT("wizards/nalle/area2/f2","north",
          "wizards/nalle/area2/b1","south",
"Western wastelands",
"You are on the western wastelands. You can not\n" +
"call the path you are walking a road, because it is in a  \n" +
"pitiful shape. There is rubble and even large rocks \n" +
"in the middle of the road.\n",3)

