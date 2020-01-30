#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/chambermaid.c");
           move_object(monster, this_object());
        }
}

TWO_EXIT("/wizards/jenny/linnake/huoneet/ylakerta29.c", "west",
           "/wizards/jenny/linnake/huoneet/ylakerta31.c", "east",
           "You are on the second floor of the castle",
           "you are walking in a small hallway, there are some painting\n" +
           "on the walls and torches are lighting your way. You hear\n" +
           "some guards speaking somewhere near and some maids are trying\n" +
           "to keep this place clean. Everything seems peaceful and calm.\n", 1)
