#include "room.h"
object hobbit;

extra_reset() {
        if (!hobbit || !living(hobbit)) {
hobbit = clone_object("/wizards/bulut/forl/monsters/hcitizen.c");
        move_object(hobbit, this_object());
      }
}
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

THREE_EXIT("wizards/bulut/forl/road25","east",
"wizards/bulut/forl/road23","west",
"wizards/bulut/forl/house4.c","enter",
"On a road in villege",
"You are standing in front of a house.\n" +
"Sandy road continues to east and west from here.\n", 3)
