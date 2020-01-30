#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
FIVE_EXIT("wizards/daoloth/mansion/tree_entrace.c", "down",
          "wizards/daoloth/mansion/tree_room2.c", "west",
          "wizards/daoloth/mansion/tree_room3.c", "east",
          "wizards/daoloth/mansion/tree_room4.c", "north",
          "wizards/daoloth/mansion/tree_room5.c", "south",
          "Tree",
          "You are standing on middle branches of tree. You see a lot\n"
          "of squirrels running around tree and eating acorns.\n"
          "Some squirrels are carrying acorns to the hole what is in\n"
          "the middle of the trunk. You see long sturdy branches going\n"
          "to every directions.\n"
          "That noise is making you crazy!\n", 3)
extra_reset() {
items = allocate(10);
items[0] = "hole";
items[1] = "Many squirrels are carrying acorn to that man-sized hole\n"
           "You wonder what kind of secret it's hiding";
}
init() {
::init();
add_action("enter_hole", "enter");
}
enter_hole(str) {
  if(str == "hole") {
    write("You crawl in to the hole.\n");
    this_player()->move_player("north#wizards/daoloth/mansion/tree_hole1.c");
    return 1;
  }
}
