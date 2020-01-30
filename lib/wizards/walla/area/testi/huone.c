#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2,monster3;

extra_reset() {
    items = allocate(2);
    items[0] = "path";
    items[1] = "A grass covered path";
    if (!monster) {
        monster = clone_object("/wizards/walla/area/lguard");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/walla/area/lguard");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/walla/area/lguard");
        move_object(monster3, this_object());
    }
}

FIVE_EXIT("wizards/walla/area/cem23","up",
"wizards/walla/workroom","south",
"wizards/walla/workroom","north",
"wizards/walla/workroom","west",
"wizards/walla/workroom","east",
"Darvox's wormroom.",
"There seems to be a dense magical darkness surrounding you. You\n" +
"sense an exit upwards and anotherone downwards nevertheless.\n", 3)
