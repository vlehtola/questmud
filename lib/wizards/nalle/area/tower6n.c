#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "room";
    items[1] = "This is a small room where the mages wait";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/redrobe");
      move_object(monster, this_object());
     }
}

THREE_EXIT("wizards/nalle/area/tower6nw","west",
"wizards/nalle/area/tower5n","down",
"wizards/nalle/area/tower6","south",
"The northern part of the 6th floor.",
"This is a small room where mages wait to be admitted to talk with Darvox. \n" +
"Darvox calls all his apprentices once a year, one at a time, to see how \n" +
"they have progressed, and if they are powerful enough, they can challenge \n" +
"Darvox's current main apprentice, who actually gets to help him. \n", 3)
