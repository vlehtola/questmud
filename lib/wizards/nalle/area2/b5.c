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

THREE_EXIT("wizards/nalle/area2/a1","west",
          "wizards/nalle/area2/b6","east",
          "wizards/nalle/area2/toystore","north",
"Avenue des Innocents (5th block)",
"You are standing on an old cobblestone road. There are signs\n" +
"indicating it is called the Avenue des Innocents. It continues to\n" +
"the west and to the east. To your west you notice a crossing of two\n" +
"roads. There is something that looks like a toystore to the north.\n",3)
