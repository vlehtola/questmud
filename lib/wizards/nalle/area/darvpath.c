#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "swamp";
    items[1] = "Occasionally small bubbles of methane emerge from the depths of the swamp";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/spirit");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/darvpath2","east",
"wizards/nalle/area/grove","west",
"The grove, leading to the Tower of High Sorcery.",
"Your surroundings are no longer as pleasant as they were some time\n" +
"ago. The path you are walking on is surrounded by a vast swamp and\n" +
"is rumoured to take you to Darvox's Tower of High Sorcery. The tower\n" +
"itself is still behind a small distance to your east. You feel very\n" +
"uneasy in here.\n", 3)
