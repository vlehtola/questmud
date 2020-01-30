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

FOUR_EXIT("wizards/nalle/area2/a2","north",
          "out: 69 21","south",
          "wizards/nalle/area2/b4","west",
          "wizards/nalle/area2/b5","east",
"Bourbon Avenue (1st block)",
"You are standing on an old cobblestone road crossing. The\n" +
"city you have arrived in, seems dead. You detect no movement\n" +
"around you and you hear no noises. The Bourbon Street leads to\n" +
"the north, and the Avenue des Innocents to the east and the west.\n" +
"The Vallis Mortis does not seem a very welcoming location \n" +
"for adventurers, but nevertheless precise maps are known to \n" +
"have been made of it \n",3)
