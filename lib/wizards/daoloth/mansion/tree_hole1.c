#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
THREE_EXIT("wizards/daoloth/mansion/tree_room1.c", "out",
           "wizards/daoloth/mansion/tree_hole2.c", "up",
           "wizards/daoloth/mansion/tree_hole3.c", "down",
           "Hole",
           "You're standing inside this huge tree. This place is much\n"
           "larger than you would have expected. You see squirrels\n"
           "everywhere. You notice that they carry those acorns to\n"
           "downstairs. You see also small ladders going up and down.\n"
           "You don't know how much longer you can stand this noise.\n", 3)
extra_reset() {
items = allocate(8);
items[0] = "ladders";
items[1] = "Ladders are very sturdy and with good luck even a giant could\n"
           "use them. Ladders are going up and down.\n"
           "You wonder why squirrels would need ladders";
items[2] = "squirrels";
items[3] = "There are squirrels everywhere and most of them are eating\n"
           "and keeping that awful noise";
call_out("echotus", 10);
}
echotus() {
  tell_room(this_object(), "Crunch Crunch!\n");
  call_out("echotus", 15); /* 30 sek */
}
