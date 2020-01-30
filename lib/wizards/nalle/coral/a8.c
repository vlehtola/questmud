#include "room.h"

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/nalle/coral/map");
   return 1;
}

FOUR_EXIT("wizards/nalle/coral/b8","north",
          "out: 69 21","south",
          "wizards/nalle/coral/b9","northeast",
          "wizards/nalle/coral/b7","northwest",
"Entrance to the Coral kingdom",
"You are standing on a sandy surface. The place you are\n" +
"in is like a massive hall, the ceiling has the form of a globe.\n" +
"There is a whole town of sea elves living here, under the sea.\n",3)

