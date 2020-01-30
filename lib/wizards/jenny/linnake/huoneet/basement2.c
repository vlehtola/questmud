#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/jail_guard.c");
           move_object(monster, this_object());
        }
}

TWO_EXIT("/wizards/jenny/linnake/huoneet/prison1.c", "north",
           "/wizards/jenny/linnake/huoneet/basement1.c", "up",
           "You are at the entrance to the prison",
           "You are standing at the entrance of a large prison complex.\n" +
           "There are some torches burning near you and some rats are wildly\n" +
           "running on the floor. All cell doors are made of iron and they seem to be\n" +
           "very good quality.\n", 1)
