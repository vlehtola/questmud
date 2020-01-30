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

TWO_EXIT("wizards/nalle/area2/c4","west",
          "wizards/nalle/area2/c6","east",
"Avenue des Nocturnes (5th block)",
"This is the Avenue des Nocturnes. The Bourbon Avenue\n" +
"crosses this avenue further to the west. This avenue\n" +
"continues east. It is very dark here, and this part of the\n" +
"town seems even more quiet then the others.\n",3)
