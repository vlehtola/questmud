#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    if (!present("sign")) {
move_object("wizards/bulut/forl/sign", this_object());
    }
}

TWO_EXIT("wizards/bulut/forl/ulos","out",
"wizards/bulut/forl/road2","north",
"On a road to village",
"You are at the entrance of Forlindon village.\n" +
"Sandy road goes to north.\n", 3)
