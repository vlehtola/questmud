#include "room.h"

object b_salamander;
object wild_cat;

extra_reset() {
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

TWO_EXIT("wizards/bulut/cave/cave4","north",
"wizards/bulut/cave/cave2","south",
"Inside of cave",
"You are standing in a dark cave.\n" +
"You can hear some moaning from far north.\n" +
"Cave continues to north and south from here\n" ,1)

