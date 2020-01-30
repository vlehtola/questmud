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

TWO_EXIT("wizards/nalle/area2/a5","north",
          "wizards/nalle/area2/a3","south",
"Bourbon Avenue (4th block)",
"You are on the Bourbon Avenue, a road that seems to\n" +
"continue north and south, to both extremities. The \n" +
"northern extremity lies a shrt way to the north, at the \n" +
"crossing of the Avenue des Lepreux. You hear whimpering.\n",3)

