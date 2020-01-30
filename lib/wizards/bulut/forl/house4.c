#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object hobbit;
int cloned;

extra_reset() {
        if (!cloned) { /* Eli resettaa vaan kerran buutissa. */
hobbit = clone_object("/wizards/bulut/gnambu.c");
        move_object(hobbit, this_object());
	cloned = 1;
      }
}

ONE_EXIT("wizards/bulut/forl/road24","out",
"In a house",
"You are in a beautiful and well decorated house.\n" +
"Sun is shining trough the window.\n" +
"A door is located in the southern wall.\n" +
"There is one obvious exit: out\n", 1)
