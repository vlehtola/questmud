#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag=1;

FOUR_EXIT("room/city/forest/for_5", "east",
      "room/city/forest/for_4", "south",
      "room/city/forest/for_16", "north",
      "room/city/forest/for_14", "west",

"In the forest",
"You are standing in a forest. \n"+ 
"You hear the peacuful singing of the birds all around you. \n"+ 
"There are fallen trees here. You notice a bunny hole in one\n"+
"of the trees. Your not certain if something lives in the \n"+ 
"hole. This is an enchanted forest. Rumors say that fairies\n"+ 
"and goblins live here.\n",
1)