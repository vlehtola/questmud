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

"Southwestern Wastelands"
"This is the southwestern corner of the city. This area here is not well \n" +
"tended, large piles of rubble, garbage and other debris lie here and \n" +
"there. The Rue des Innocents is to your south and the wastelands \n" +
"continue to the north.\n",3)
