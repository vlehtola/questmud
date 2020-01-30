#include "room.h"

object salamander;
object b_salamander;

extra_reset() {
        if (!salamander || !living(salamander)) {
salamander = clone_object("/wizards/bulut/cave/monsters/salamander.c");
        move_object(salamander, this_object());

              }

        if (!b_salamander || !living(b_salamander)) {
b_salamander = clone_object("/wizards/bulut/cave/monsters/b_salamander.c");
        move_object(b_salamander, this_object());

              }

}


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

TWO_EXIT("wizards/bulut/cave/cave3","north",
"wizards/bulut/cave/cave1","south",
"Inside of cave",
"You are standing in a dark cave.\n" +
"You can hear some moaning from far north.\n" +
"Cave continues to north and south from here\n" ,1)

