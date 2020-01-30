#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "corpses";
    items[1] = "Corpses of horribly massacred bodies";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/liveone2");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/towerd1","west",
"A cavity.",
"This room has not been made by men. It is just a cavity that has been\n" +
"created by chipping away little pieces of rock. Dismembered corpses\n" +
"are lying here and there on the ground. It seems there must be some-\n" +
"thing unholy living in this place. You can see glimpses of light from\n" +
"from the west, where you came from.\n", 1)

