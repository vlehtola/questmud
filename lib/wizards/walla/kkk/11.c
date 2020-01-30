#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/kkk/monsters/dragon");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/walla/kkk/10", "west",
          "The lair of the Dragon",
         "This is a small room, hidden low underneath the clavern. It is generally meant that\n" +
         "no one comes here. The Dragon that stays here every now and then is not keen\n" +
          "of you coming here. \n", 1)
