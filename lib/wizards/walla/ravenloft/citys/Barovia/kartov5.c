#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
    if (!present("sign")) {
        move_object("wizards/walla/ravenloft/citys/Barovia/innsign", this_object());
    }

    if (!items) {
        items = allocate(2);
        items[0] = "plaque";
        items[1] = "You are on Kartov street, 1 north from the Central Square.\n" +
                   "To the east is the bar, and to the west is the whorehouse.";
    }

} 
FOUR_EXIT("wizards/walla/ravenloft/citys/Barovia/cs", "south",
         "wizards/walla/ravenloft/citys/Barovia/kartov4", "north",
         "wizards/walla/ravenloft/citys/Barovia/inn", "east",
         "wizards/walla/ravenloft/citys/Barovia/whorehouse", "west",
          "On Kartov Street, just north of the Central Square of Barovia",
         "This is Kartov street. It has been named after the well liked Burgomaster of the city.\n" +
         "There is a cobblestone street that continues to the north, and to the south the big tower of \n" +     
         "Central Square can be seen. To the east laughter, and smells of freshly brewed beer come.\n" +
         "And from the west, moanings of various bitches can be heard. You think to yourself, that \n" +
         "this is a wonderful town. A plaque on the wall tells you where you are situated.\n", 1)

