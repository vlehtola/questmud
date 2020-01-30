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

THREE_EXIT("wizards/nalle/area2/b2","west",
          "wizards/nalle/area2/b4","east",
          "wizards/nalle/area2/graveyard","north",
"Avenue des Innocents (3rd block)",
"You are standing on an old cobblestone road. There are signs\n" +
"indicating it is called the Avenue des Innocents. It continues to\n" +
"the west and to the east. There is a large gateway leading to the\n" +
"graveyard to the north.\n",3)
