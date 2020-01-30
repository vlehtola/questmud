#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/bazaarman");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/walla/area/bazaar31", "south",
         "wizards/walla/area/bazaar22", "east",
         "wizards/walla/area/bazaar12", "north", 	
"In the bazaar of Jericho",
         "You are in the western part of the bazaar.\n" +
         "This is the place where the people of Jericho meet to discuss their problems.\n" +
         "Shopkeepers scream out their products what their heads can take. \n" +
         "Everyone seems happy. \n", 3)
