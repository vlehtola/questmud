#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monster,monster2,monster3;
 
extra_reset() {
    items = allocate(2);
    items[0] = "path";
    items[1] = "A grass covered path";
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/lebzomppa1");
        move_object(monster, this_object());
    }
if (!monster2) {
        monster2 = clone_object("/wizards/walla/area/monsters/lebzomppa2");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/walla/area/monsters/lebzomppa3");
        move_object(monster3, this_object());
    }
}
 
FIVE_EXIT("wizards/walla/area/ispep-3","up",
"wizards/walla/area/undergravesouth","south",
"wizards/walla/area/yksnorth/lebway2","north",
"wizards/walla/area/undergravewest","west",
"wizards/walla/area/undergraveeast","east",
"The Sewer system",
"You have arrived at a crossing\n" +
"Exits lead to many directions.\n", 3)


