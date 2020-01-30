#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3)

    if (!monster) {
        monster = clone_object("/wizards/nalle/seaelf1");
        move_object(monster, this_object());
    }
}

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/nalle/coral/map");
   return 1;
}

FOUR_EXIT("wizards/nalle/coral/c8","north",
          "wizards/nalle/coral/a8","south",
          "wizards/nalle/coral/b9","east",
          "wizards/nalle/coral/b7","west",
"Southern part of the Coral kingdom",
"You are standing on a sandy surface. The place you are\n" +
"in is like a massive hall, the ceiling has the form of a globe.\n" +
"There is a whole town of sea elves living here, under the sea.\n" +
"You see huts to the northwest and northeast.\n",3)

