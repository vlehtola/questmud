#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "corpses";
    items[1] = "Corpses of horribly desecrated bodies";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/liveone2");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/towerd1","west",
"A cavity.",
"This room has not been made by man. It is just a cavity that has been created  \n" +
"by chipping away little pieces of rock. Dismembered corpses are lying on the \n" +
"ground here and there. There must be something unholy living in this place. \n" +
"You can see glimpses of light from the west, where you came from. \n", 1)

