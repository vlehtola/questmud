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

TWO_EXIT("wizards/nalle/area2/d7","north",
          "wizards/nalle/area2/f5","south",
"Eastern wastelands",
"You are standing on a dirt path on the eastern side of the\n" +
"town. A pretty well formed road lies to your north, it is\n" +
"called the Avenue des Lepreux.The dirt path continues \n" +
"to your south. You hear faint moaning from the north.\n",3)
