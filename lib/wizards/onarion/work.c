#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monsu;

extra_reset() {
    if (!monsu) {
        monsu = clone_object("/world/monsters/ant1.c");
        move_object(monsu, this_object());
    }
}

ONE_EXIT("world/city/inn", "inn",
"Gorka's workroom",
"This is Gorka's workroom, better not to spam him.\n" +
"Especially when he is working.\n", 3)


