#include "room.h"

object salamander;
object wild_cat;
object b_salamander;
extra_reset() {

        if (!salamander || !living(salamander)) {
salamander = clone_object("/wizards/bulut/cave/monsters/salamander.c");
        move_object(salamander, this_object());

              }

        if (!wild_cat || !living(wild_cat)) {
wild_cat = clone_object("/wizards/bulut/cave/monsters/wild_cat.c");
        move_object(wild_cat, this_object());

              }

        if (!b_salamander || !living(b_salamander)) {
b_salamander = clone_object("/wizards/bulut/cave/monsters/b_salamander.c");
        move_object(b_salamander, this_object());

              }

}


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

TWO_EXIT("wizards/bulut/cave/cave5","east",
"wizards/bulut/cave/cave3","south",
"Inside of cave",
"You are standing in a dark cave.\n" +
"You can hear some moaning from far north.\n" +
"Cave continues to east and south from here\n" ,1)

