#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/knight.c");
           move_object(monster, this_object());
        }
}

FIVE_EXIT("/wizards/jenny/linnake/huoneet/piha1.c", "west",
           "/wizards/jenny/linnake/huoneet/piha8.c", "northwest",
           "/wizards/jenny/linnake/huoneet/piha7.c", "north",
           "/wizards/jenny/linnake/huoneet/piha6.c", "northeast",
           "/wizards/jenny/linnake/huoneet/piha3.c", "east",
           "You are outside the castle",
           "You are walking outside the castle, there are trees around you\n" +
           "and it looks like knights are using this place as their training\n" +
           "zone. There are also some odd looking bushes nearby, who knows what\n" +
           "there might be.\n", 1)