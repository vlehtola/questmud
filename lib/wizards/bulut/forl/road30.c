#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object hobbit;

extra_reset() {
        if (!hobbit || !living(hobbit)) {
hobbit = clone_object("/wizards/bulut/forl/monsters/hcitizen.c");
        move_object(hobbit, this_object());
      }
}

ONE_EXIT("wizards/bulut/forl/road27","west",
"In the village",
"You are walking on a small path.\n" +
"Road ends here.\n",3)
