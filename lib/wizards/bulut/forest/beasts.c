#include "room.h"

object beast_mark,beast_master;


init() {
   ::init();
add_action("join", "join");
}

extra_reset() {
        if (!beast_master || !living(beast_master)) {
        beast_master = clone_object("/wizards/bulut/forest/beast_master.c");
        move_object(beast_master, this_object());
                                                    }
              }


join(str) {
write("Were-wolf grabs your neck and BITES!\n");
write("You feel TERRIBLE PAIN.\n");
    beast_mark = clone_object("/wizards/bulut/jep.c");
    move_object(beast_mark, this_player());

return 1;
          }

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();



ONE_EXIT("wizards/bulut/forest/forest5","south",
"In the forest",
"Tamaon toitoitoi.. nose\n" +
"fiksaa descit\n", 1)
