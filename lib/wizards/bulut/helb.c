#include "room.h"

object wolf;

init() {
add_action("search", "search");
       }

search(str) {
if (str=="bushes") {
      write("You discover a secret passage!\n");
      write(".. and sneak through the bush.\n");
      move_object(this_player(), "/wizards/bulut/forest/beasts.c");

return 1;
                }
            }

extra_reset() {
        if (!wolf || !living(wolf)) {
wolf = clone_object("/wizards/bulut/forest/wolf.c");
        move_object(wolf, this_object());

                                    }
              }

id(str) {
    return str == "door";
}



#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();


TWO_EXIT("wizards/bulut/forest/forest6","east",
"wizards/bulut/forest/forest4","south",
"In the forest",
"Light is blinking through the northern bushes\n" +
"Path continues to east and south from here\n", 1)
