#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "coffin";
    items[1] = "A wooden coffin";
}

ONE_EXIT("wizards/nalle/area/darvroom","north",
"Southern part of Darvox's workroom.",
"You are now in the southern part of Darvox's workroom. There\n" +
"is a distinctive smell of decay here, which indicates that this  \n" +
"room could be used for necromantic research.\n", 2)
