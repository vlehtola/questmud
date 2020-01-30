#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(2);
    if (!monster) {
        monster = clone_object("/wizards/walla/strahd/monsters/wolf");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/walla/strahd/path7", "east",
         "wizards/walla/strahd/mpath", "west",
         "On a road, leading up to the mountainous area",
         "As you walk further on the road, the road fades away, and only a path\n" +
         "continues its way upwards. Although people have warned you many times\n" +
         " not to go to the\n" +
         "misty area, you seem tempted to find out what lies ahead.\n", 2)
