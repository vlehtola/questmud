#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/dl/monsters/secretdg");
        move_object(monster, this_object());
    }
}
ONE_EXIT("wizards/walla/dl/rooms/xaktsaroth/gd4", "south",
"The home of a gully dwarf",
        "This room is nothing but a mere shitdump.\n" +
        "The only furniture is a broken bed and a painting with nothing\n" +
"on it. The smell here is intolerable.\n", 3)

