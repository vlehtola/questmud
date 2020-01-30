#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
    if (!present("sign")) {
         move_object("wizards/walla/peepseye/vorticons/sign", this_object());
    }
    if (!items) {
        items = allocate(2);
        items[0] = "skulls";
        items[1] = "The cobblestone floor is covered with these bloody skulls. They seem\n" +
                   "to have been literraly torn apart from the rest of the body.";
    }
}
ONE_EXIT("wizards/walla/peepseye/vorticons/b8", "south",
         "At the mouth of a dark cave.",
         "You have entered to a dark place. This place really gives you the creeps,mostly \n" +
         "due to the fould stench here. You see the cavern stretching further down to the \n" +
         "south, and you see a sign, warning of dangers ahead.\n" +
         "and a pile of skulls on the floor,\n", 2)
 
 

