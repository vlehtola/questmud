#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/citizen");
        move_object(monster, this_object());
    }
}
 
FOUR_EXIT("wizards/walla/area/ujar4", "north",
         "wizards/walla/area/sgate", "south",
         "wizards/walla/area/alchemistshop", "west",
         "wizards/walla/area/guardhouse","east",
         "On Ujar street ",
         "You are standing on Ujar street, the main street of Jericho .\n" +
         "To whe west is the alchemist shop, where hopefully someone finds the way to make gold.\n" +
         "To the east is the guardhouse, where the gateguards live. \n" +
         "Mumbling and laughter can be heard from there. \n", 3)
