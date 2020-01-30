#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster,monster2;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/strahd/monsters/scientist1");
        move_object(monster, this_object());
    }
 
if (!monster2) {
        monster2 = clone_object("/wizards/walla/strahd/monsters/scientist2");
        move_object(monster2, this_object());
    }
}
 
ONE_EXIT("wizards/walla/workroom", "pois",
         "Deep under the Castle Ravenloft",
         "You enter a sinister place, with a big large table in front. It contains different mixes\n" +
         "and potions. Also, a brain is situated on the middle of the table.\n", 3)
