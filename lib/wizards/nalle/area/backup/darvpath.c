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
        monster = clone_object("/wizards/nalle/area/spirit");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/darvpath2","east",
"wizards/nalle/area/grove","west",
"The grove, leading to the Tower of High Sorcery.",
"Your surroundings are no longer pleasant as they were some time ago. The \n" +
"path you are walking on is surrounded by a vast swamp and is rumoured to  \n" +
"take you to Darvox's Tower of High sorcery. The tower itself is still a small\n" +
"way to the east. You feel very uneasy here.\n", 3)
