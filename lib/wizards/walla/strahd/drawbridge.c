#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);
    if (!monster) {
        monster = clone_object("/wizards/walla/strahd/monsters/drawbridgemoko");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/walla/strahd/path1", "south",
         "wizards/walla/strahd/courtyard", "north",
         "The drawbridge",
         "You are the drawbridge to the castle Strahd. You can see very far from here, due \n" +
         "to the high altitude of the castle. A small and grassy path leads south from here,\n" +
         "away from the evil forces of darkness. \n", 3)
