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

THREE_EXIT("wizards/nalle/area2/c1","east",
          "wizards/nalle/area2/f1","south",
          "wizards/nalle/area2/f3","north",
"Western wastelands",
"You are standing on a partially destroyed crossing. The\n" +
"Avenue des Nocturnes leads to the east, and a path, if\n" +
"one can call it that, leads to the north and to the south.\n" +
"To the east the Avenue des Nocturnes is illuminated\n" +
"by pale streetlights, but nevertheless the shadows \n" +
"remain curiously long.\n",3)
