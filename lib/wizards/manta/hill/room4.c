#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster4,monster5;

extra_reset()   {
        if (!monster4)  {
        monster4 = clone_object("wizards/manta/castle/dem1.c");
        move_object(monster4, this_object());
        }
        if(!monster5)   {
        monster5 = clone_object("wizards/manta/castle/dem1.c");
move_object(monster5, this_object());
        }
}

FOUR_EXIT("wizards/manta/hill/room7.c", "north",
            "wizards/manta/hill/room6.c", "east",
            "wizards/manta/hill/room3.c", "south",
            "wizards/manta/hill/room5.c", "west",
            "A central square",
            "You are standing in a desolated square which used to be full of\n" +
            "people chatting and laughing.\n", 3)

                
