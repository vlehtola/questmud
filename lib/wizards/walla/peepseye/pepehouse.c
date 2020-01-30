#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/eq/objs/pepe3");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/peepseye/3", "out",
         
         "The hut of Pepe.",
         "This is the hut of Pepe. Pepe is the oldest on this island, and it is rumoured that he is the one \n" +
         "responsible for this whole place. However, nowadays, Pepe has retired, and is now, nothing \n" +
         "but an old geezer, wasting his time looking at the sea.\n", 3)
 
