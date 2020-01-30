#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "pool";
    items[1] = "You start to feel dizzy as you watch the swirling colours";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/liveone");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/towerd","up",
"wizards/nalle/area/towerd2","down",
"wizards/nalle/area/livingroom","east",
"The room of living creations.",
"This is the room where Darvox does an important part of his spellcasting. \n" +
"That is, the living creations. The creations of failed spells are hideous \n" +
"creatures, that would devour anything living, except their creator whom \n" +
"they fear from the bottom of their misformed hearts. There is a large \n" +
"pool in the middle of the room, emitting blue light. \n", 1)

