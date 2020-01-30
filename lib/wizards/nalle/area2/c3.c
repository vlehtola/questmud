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

THREE_EXIT("wizards/nalle/area2/c2","west",
          "wizards/nalle/area2/nocjalep","north",
          "wizards/nalle/area2/a3","east",
"Avenue des Nocturnes (3rd block)",
"You are on the Avenue des Nocturnes. The Bourbon \n" +
"Avenue is to your east and to your north you notice\n" +
"an entry to an old and dark little boutique. The air \n" +
"here is still and bitterly cold. The only signs of life\n" +
"you notice here are a few stray black cats, that are eyeing\n" +
"you peculiarry.\n",3)
