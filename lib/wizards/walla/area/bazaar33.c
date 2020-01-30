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

TWO_EXIT("wizards/walla/area/bazaar23", "north",
              "wizards/walla/area/bazaar32", "west",
      "In the bazaar of Jericho",
         "You are in the southeastern part of the bazaar.\n" +
         "This is the place where the people of Jericho meet to discuss their problems.\n" +
         "Shopkeepers scream out their products what their heads can take. \n" +
         "Everyone seems happy. \n", 3)
