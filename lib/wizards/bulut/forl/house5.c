#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object hobbit;

extra_reset() {
        if (!hobbit || !living(hobbit)) {
hobbit = clone_object("/guilds/fighter/acrocitizen.c");
        move_object(hobbit, this_object());
      }
}

ONE_EXIT("wizards/bulut/forl/road28","out",
"In a house",
"You are in a beautiful and well decorated house.\n" +
"Sun is shining trough the window.\n", 3)
