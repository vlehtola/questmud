#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "The stairway leads down";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/wraith");
      move_object(monster, this_object());  
     }
}

TWO_EXIT("wizards/nalle/area/towerd1","up",
"wizards/nalle/area/towerd3","down",
"Under the room of living creations.",
"Living beings, with the exception of Darvox, are never let down here. Some \n" +
"curious apprentices are rumoured to have sneaked past the livingones down \n" +
"here, but disciplinary action has never been necessary. It would be wise for \n" +
"to leave immediately, you can sense a powerful aura of evil here. \n", 1)

