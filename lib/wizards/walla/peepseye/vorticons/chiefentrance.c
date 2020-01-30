#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster,monster2;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/vortguard");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster = clone_object("/wizards/walla/peepseye/monsters/vortguard");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/peepseye/vorticons/c7", "west",
         "wizards/walla/peepseye/vorticons/chiefroom", "portal",
         "At the gate to the Vorticon Chief.",
         "You have entered the hall where the guards stand in order to protect their chief,\n" +
         "the Vorticon Master. There is not however a door leading straigh to the chief, but\n" +
         " a sort of portal.\n", 1)
