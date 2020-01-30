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

ONE_EXIT("wizards/bulut/forl/road31","out",
"In a house",
"You are in a beautiful and well decorated house.\n" +
"Sun is shining trough the window.\n" +
"A door is located in the eastern wall.\n" +
"There is one obvious exit: out\n", 1)
