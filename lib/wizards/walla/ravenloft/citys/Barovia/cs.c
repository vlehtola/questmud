#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
    if (!present("sign")) {
        move_object("wizards/walla/ravenloft/citys/Barovia/cstower", this_object());
    }
    if (!items) {
        items = allocate(2);
        items[0] = "clock";
        items[1] = "There is an iron clock on top of the tower, but it seems to be broken now.\n" +
                   "The time has stopped at 21 minutes past 9.";
    }
}
 
FOUR_EXIT("wizards/walla/ravenloft/citys/Barovia/kartov7", "south",
         "wizards/walla/ravenloft/citys/Barovia/kartov5", "north",
         "wizards/walla/ravenloft/citys/Barovia/sasha7", "east",
         "wizards/walla/ravenloft/citys/Barovia/sasha5", "west",
          "Central Square of Barovia",
         "This is the central square of Barovia. Lights can be seen from different parts of the dark city.\n" +
         "The cobblestones that this square is made of continues to four directions. Likewise to the\n" +     
         "suns movements, Kartov street goes in an East - West direction. Likewise, to the North and\n" +
         "South goes Sasha Avenue, named after the Burgomasters daughter. At the Central Square\n" +
         "is a big tower, which seems to have a clock on it.\n", 1)

