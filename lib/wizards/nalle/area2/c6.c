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

TWO_EXIT("wizards/nalle/area2/c5","west",
          "wizards/nalle/area2/f5","east",
"Avenue des Nocturnes (6th block)",
"This is the Avenue des Nocturnes. The eastern wastelands\n" +
"are located to your east. This is the eastern extremity of\n" +
"avenue. It is very dark here, and this part of the\n" +
"town seems even more quiet then the others.\n",3)
