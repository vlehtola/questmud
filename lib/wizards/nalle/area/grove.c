#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2;

extra_reset() {
    items = allocate(2);
    items[0] = "swamp";
    items[1] = "The smell of the decaying plants is awful";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/spectre2");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/monsters/spectre2");
        move_object(monster2, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/pathe","west",
"wizards/nalle/area/darvpath","east",
"The western part of the grove.",
"You are in the swamps between Chamron and the Darvox's tower.\n" +
"The atmosphere in this part of the swamp feels very annoying,\n" +
"almost as if someone would be watching over you. You are\n" +
"quite certain, that when you entered the room, a black crow\n" +
"took off from a nearby tree and flew into the black tower's\n" +
"upper floors. It seems like Darvox would try to show, that\n" +
"your presence was not left unnoticed.\n", 3)
