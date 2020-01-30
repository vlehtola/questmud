#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monster,monster2,monster3;
 
extra_reset() {
    items = allocate(2);
    items[0] = "counter";
    items[1] = "A counter, like in any bar";
    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/barpirate");
        move_object(monster, this_object());
    }
if (!monster2) {                
        monster2 = clone_object("/wizards/walla/peepseye/monsters/pirate2");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/walla/peepseye/monsters/pirate3");
        move_object(monster3, this_object());
    }
}
 
TWO_EXIT("wizards/walla/peepseye/4","out",
"wizards/walla/peepseye/backroom","curtain",
"In a tree, converted into a bar.",
"This bar looks like a normal bar. Pirates sit around tables here, and seem to \n" +
"be drinking some sort of liquour because they seem to be getting drunk.\n", 3)

