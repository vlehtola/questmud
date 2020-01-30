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

EIGHT_EXIT("/wizards/jenny/linnake/huoneet/piha14.c", "west",
           "/wizards/jenny/linnake/huoneet/piha19.c", "northwest",
           "/wizards/jenny/linnake/huoneet/piha20.c", "north",
           "/wizards/jenny/linnake/huoneet/piha26.c", "northeast",
           "/wizards/jenny/linnake/huoneet/piha27.c", "east",
           "/wizards/jenny/linnake/huoneet/piha28.c", "southeast",
           "/wizards/jenny/linnake/huoneet/piha12.c", "south",
           "/wizards/jenny/linnake/huoneet/piha11.c", "southwest",
           "You are outside the castle",
           "You are walking outside the castle, there are trees around you\n" +
           "and it looks like knights are using this place as their training\n" +
           "zone. There are also some odd looking bushes nearby, who knows what\n" +
           "there might be.\n", 1)
