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

TWO_EXIT("wizards/nalle/area2/f2","west",
          "wizards/nalle/area2/c2","east",
"Avenue des Nocturnes (1st block)",
"You are on the western end of the Avenue des Nocturnes.\n" +
"The road continues to the east, and there are some waste- \n" +
"lands to the west. Despite the illuminating lamplights, it is\n" +
"indeed very dark and eerie here. The silence is threatening.\n",3)
