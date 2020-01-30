#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

FOUR_EXIT("room/city/forest/for_1", "east",
      "room/city/forest/for_4", "west",
      "room/city/forest/for_3", "south",
      "room/city/forest/for_5", "north",

"In the forest",
"You are standing in a forest. \n"+ 
"You hear the peacuful singing of the birds all around you. \n"+ 
"There are fallen trees here. You notice a bunny hole in one\n"+
"of the trees. Your not certain if something lives in the \n"+ 
"hole. This is an enchanted forest. Rumors say that fairies\n"+ 
"and goblins live here.\n",
1)

object goblin;

extra_reset() {
    if (!goblin) {
        goblin = clone_object("/obj/goblin");
        move_object(goblin, this_object());
    }
}


