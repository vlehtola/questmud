#include "room.h"
object hobbit;

extra_reset() {
      if (!hobbit || !living(hobbit)) {
hobbit = clone_object("/wizards/bulut/forl/monsters/hcitizen.c");
        move_object(hobbit, this_object());
      }
      items = allocate(2);
      items[0] = "table";
      items[1] = "This is an ordinary looking table";
}

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

ONE_EXIT("wizards/bulut/forl/road3","out",
"In a house",
"You are in a beautiful and well decorated house.\n" +
"Sun is shining through the window.\n" +
"There is a table on north wall.\n", 3)
