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

THREE_EXIT("wizards/nalle/area2/b5","west",
          "wizards/nalle/area2/b7","east",
          "wizards/nalle/area2/hotel","north",
"Avenue des Innocents (6th block)",
"You are standing on an old cobblestone road. There are signs\n" +
"indicating it is called the Avenue des Innocents. It continues to\n" +
"the west and to the east. There is some sort of an entry to the north.\n",3)
