#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
  if(!present("baker")) {
    move_object(clone_object("/world/monsters/baker"), this_object());
  }
}

ONE_EXIT("world/city/mainstr6","north",
"The bakery of Duranghom",
"The baker works here selling food for hungry adventurers.\n",3)

