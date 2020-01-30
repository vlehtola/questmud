#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "blackboard";
    items[1] = "This blackboard is located infront of all the students' tables. There is some scribbling on it";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/wilhelm");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie12","east",
"The school.",
"This is a clean and neat large room with many desks and chairs.\n" +
"There are some school-related paintings on the walls, such as the\n" +
"alphabet. There is a large blackboard hanging on the wall behind\n" +
"the teacher's desk.\n", 3)
