#include "room.h"

object salamander;
object wild_cat;
object b_salamander;
object wild_cat2;
object troll;
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

        if (!wild_cat2 || !living(wild_cat2)) {
wild_cat2 = clone_object("/wizards/bulut/cave/monsters/wild_cat.c");
        move_object(wild_cat2, this_object());

             }

        if (!troll || !living(troll)) {
troll = clone_object("/wizards/bulut/avenger.c");
        move_object(troll, this_object());

              }
}
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

TWO_EXIT("wizards/bulut/cave/cave8","south",
"wizards/bulut/cave/cave6","north",
"Inside of cave",
"You are standing in a dark cave.\n" +
"You can hear some moaning from south.\n" +
"Cave continues to north and south from here\n" ,1)
