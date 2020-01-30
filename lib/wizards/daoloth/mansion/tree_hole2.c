#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
TWO_EXIT("wizards/daoloth/mansion/tree_hole1.c", "down",
         "wizards/daoloth/mansion/tree_hole4.c", "up",
         "Inside tree",
         "Wow, you have never seen anything like this!\n"
         "You stand in a tiny room. Somehow this room has been engraved\n"
         "inside this huge tree so that you can even stand on the little\n"
         "floor. You see lot of hay all over the floor. Maybe this is\n"
         "somekind of sleeping room. Some squirrels are sleeping on the\n"
         "floor and some seems to be very angry while you're standing\n"
         "here. You see small ladders going up and down.\n"
         "You don't know how much longer you can stand this noise.\n", 3)
extra_reset() {
items = allocate(8);
items[0] = "ladders";
items[1] = "Ladders are very sturdy and with good luck even a giant could\n"
           "use them. Ladders are going up and down.\n"
           "You wonder why squirrels would need ladders";
items[2] = "squirrels";
items[3] = "There are squirrels everywhere! Some are sleeping, but most"
           "of them are eating and keeping that awful noise";
}
