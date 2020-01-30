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

THREE_EXIT("wizards/nalle/area2/d5","east",
          "wizards/nalle/area2/a4","south",
          "wizards/nalle/area2/d4","west",
"Bourbon Avenue (5th block)",
"You are standing on an old cobblestone road crossing. The\n" +
"stench here is revolting. You see faint figures of whimpering\n" +
"creatures to your west and to your east, on the Avenue des\n" +
"Lepreux. The Bourbon Avenue continues back to the south,\n" +
"but no longer to the north. To the north there is but a steep \n" +
"rocky cliff, hundreds of feet high. It seems perfectly  \n" +
"unescalable.\n",3)
