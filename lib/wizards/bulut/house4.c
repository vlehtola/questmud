/* /wizards/bulut/forl/house4.c */
#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object door, hobbit;

extra_reset() {
    if (!present("door")) {
move_object("wizards/bulut/forl/door", this_object());
}

        if (!hobbit || !living(hobbit)) {
hobbit = clone_object("/wizards/bulut/forl/monsters/hcitizen.c");
        move_object(hobbit, this_object());
      }
}

ONE_EXIT("wizards/bulut/forl/road24","out",
"In a house",
"You are in a beautiful and well decorated house.\n" +
"Sun is shining trough the window.\n" +
"A door is located in the southern wall.\n", 1)
