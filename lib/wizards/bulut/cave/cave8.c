#include "room.h"

object king;

extra_reset() {
        if (!king || !living(king)) {
king = clone_object("/wizards/bulut/cave/monsters/king.c");
        move_object(king, this_object());

              }

}


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

ONE_EXIT("wizards/bulut/cave/cave7","north",
"Inside of cave",
"You are standing in the end of tunnel.\n" +
"Cave goes back to north from here\n" ,1)
