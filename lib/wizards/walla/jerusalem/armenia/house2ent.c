#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/jerusalem/monsters/yeshiva");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/walla/jerusalem/armenia/21", "east",
         "The house of Yeshiva Hesed El",
         "This humble home belongs to a great architect from Bagdad, Yeshiva\n" +
         "Hesed El. He has sworn by the beard of many prophets, that he will be the one,\n" +
         "thet gets the honour of building the great Ashkenazi, next to the Chabad synagogue.\n", 3)


