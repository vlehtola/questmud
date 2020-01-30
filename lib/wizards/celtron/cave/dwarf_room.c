#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();
int moko;

extra_reset() {
  set_not_out(1);
  if(moko == 0) {
    moko=1;
    move_object(clone_object("/wizards/celtron/cave/dwarf/dwarf"),
	this_object());
  }
}

ONE_EXIT(  "/wizards/celtron/cave/cave1", "north",
	   "Dim tunnel",
	   "No light sources are nearby, making this place really dim.\n" +
	   "Walls, ceiling and floor are all pure stone.\n" +
	   "Some water drops from ceiling making soft sounds.\n", 1)
