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

TWO_EXIT("wizards/nalle/area2/a3","north",
          "wizards/nalle/area2/a1","south",
"Bourbon Avenue (2nd block)",
"You are on the Bourbon Avenue, a road that seems to\n" +
"continue north and south, to both extremities. The \n" +
"entry to the town seems close down south, and you \n" +
"feel uneasy, looking up north, to the Avenue des Nocturnes.\n",3)
