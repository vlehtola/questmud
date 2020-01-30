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

THREE_EXIT("wizards/nalle/area2/c1","west",
          "wizards/nalle/area2/store1","north",
          "wizards/nalle/area2/c3","east",
"Avenue des Nocturnes (2nd block)",
"You are standing on a small crossing. A little path\n" +
"leads to the north, between two buildings. The Avenue\n" +
"des Nocturnes leads to the east and to the west. The\n" +
"air here is still and bitterly cold. The only signs of life\n" +
"you notice here are a few stray black cats, that are eyeing\n" +
"you peculiarry.\n",3)
