#include "room.h"

object troll;

extra_reset() {
        if (!troll || !living(troll)) {
troll = clone_object("/wizards/bulut/forest/troll.c");
        move_object(troll, this_object());
                                    }
              }

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();


TWO_EXIT("wizards/bulut/forest/forest13","north",
"guilds/fighter/berserker","west",
"In a house",
"You are standing inside of an ugly house.\n" +
"There is smelly crap everywhere.\n", 1)
