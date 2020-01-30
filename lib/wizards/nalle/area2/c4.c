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

TWO_EXIT("wizards/nalle/area2/a3","west",
          "wizards/nalle/area2/c5","east",
"Avenue des Nocturnes (4th block)",
"This is the Avenue des Nocturnes. The Bourbon Avenue\n" +
"is situated to your west, and this road continues to the\n" +
"east. It is very dark here, and this part of the town\n" +
"seems even more quiet then the others.\n",3)

