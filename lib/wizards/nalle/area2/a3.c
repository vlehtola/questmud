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

FOUR_EXIT("wizards/nalle/area2/a4","north",
          "wizards/nalle/area2/a2","south",
          "wizards/nalle/area2/c3","west",
          "wizards/nalle/area2/c4","east",
"Bourbon Avenue (3rd block)",
"You are standing on an old cobblestone road crossing. The\n" +
"atmosphere here is agonizing. You see noone, you hear noone\n" +
"but you are certain that someone is watching you. You try to\n" +
"gaze into the shadows but find nothing suspectible. The Avenue\n" +
"des Nocturnes is situated both to your east and to your west. \n" +
"As you peer to your both sides once more and notice that \n" +
"the shadows seem to lengthen, the further you walk that avenue.\n",3)
