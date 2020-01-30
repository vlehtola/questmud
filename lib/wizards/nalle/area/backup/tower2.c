#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "mages";
    items[1] = "The mages are busy and take no notice of you.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/redrobe");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/tower3","up",
"wizards/nalle/area/tower2n","north",
"wizards/nalle/area/tower1","down",
"The first floor.",
"This room is used as the place where the low ranking red robed apprentices \n" +
"train and study. Darvox doesen't bother to come here much, most of the teaching \n" +
"is done by higher ranking black robed mages. The mages here are very skilled,\n" +
"despite their low position. \n", 3)
