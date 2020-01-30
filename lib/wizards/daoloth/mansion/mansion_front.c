#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
TWO_EXIT("wizards/daoloth/mansion/entrace_room", "enter",
         "wizards/daoloth/mansion/path", "south",
         "Front door of mansion",
         "You stand front of huge mansion. Mansion seems to be abandoned.\n"
         "You don't have any idea why because it would be nice place to\n"
         "live after repairs. But now mansion seems to be in bad condition.\n"
         "Front door is broken and windows are sealed with boards. Chimney\n"
         "seems to be collapsed many years ago.\n"
         "It's unnaturaly quiet here. You don't hear any birds singing.\n", 3)
extra_reset() {
items = allocate(90);
items[0] = "mansion";
items[1] = "Mansion is really big. It has atleast two floors. No one hasn't\n"
           "painted house for many years but it still has some marks of red\n"
           "paint on walls";
items[2] = "windows";
items[3] = "You see one of the cellar windows has loose boards. Maybe you\n"
           "can tear them off";
items[4] = "door";
items[5] = "Front door is in two pieces. You have no idea what has\n"
           "happened to it";
items[6] = "chimney";
items[7] = "There are not too much left. Looks like that chimney has\n"
           "somehow exploded all over roof";
}
