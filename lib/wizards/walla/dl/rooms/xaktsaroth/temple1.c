#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
    if (!present("sign")) {
         move_object("wizards/walla/dl/objs/mishakalstatue", this_object());
    }
    if (!items) {
        items = allocate(2);
        items[0] = "altar";
        items[1] = "An altar, to praise the godess of healing, Mishakal stands here\n" +
                   "Although gods were probably wiped out during the Cataclysm, you have\n" +
           "a safe feeling here.";
    }
}
ONE_EXIT("wizards/walla/dl/rooms/xaktsaroth/templesouth", "south",                
         "In the temple of Mishakal.",
         "This place makes you welcome, made you comfortable the moment you walked\n" +
         "in. There is something about this place and that statue. It almost seemes\n" +
         "like it's more than a statue.\n", 2)
 

