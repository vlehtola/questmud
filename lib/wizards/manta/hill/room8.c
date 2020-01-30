#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
object monster14,monster15;

extra_reset() {
        if(!monster14) {
        monster14 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(monster14, this_object());
        }
        if(!monster15) {
         monster15 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(monster15, this_object());
        }
}

ONE_EXIT("/wizards/manta/hill/room5.c", "north",
         "Slaughterhouse",
         "This is slaughterhouse where animals for fortress were slaughtered.\n" +
         "You can still see rotten remains of animals and humans here.\n" +
         "seems that not only animals met their fate here.\n", 3)











