#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
int i;

extra_reset() {
  set_not_out(1);
  if(!i) {
    move_object(clone_object("/wizards/celtron/cave/orc/orc_barbarian"),
	this_object());
    i = 1;
  }
}

TWO_EXIT(  "/wizards/celtron/cave/cave1", "northwest",
	   "/wizards/celtron/cave/cave6", "east",
	   "Dim tunnel",
	   "No light sources are nearby, making this place really dim.\n" +
	   "Walls, ceiling and floor are all pure stone.\n" +
	   "Some water drops from ceiling making soft sounds.\n", 1)
