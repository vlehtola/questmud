#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "pool";
    items[1] = "You start to feel dizzy as you watch the swirling colours in the pool";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/liveone");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/towerd","up",
"wizards/nalle/area/towerd2","down",
"wizards/nalle/area/livingroom","east",
"The room of living creations",
"This is the room where Darvox does the most important part of his\n" +
"spellcasting, which is, the living creations. The creations of failed\n" +
"spells are hideous creatures, who would devour anything living, except\n" +
"their creator whom they fear from the bottom of their deformed hearts.\n" +
"There is a large pool in the middle of the room, emitting a blue light.\n", 1)

