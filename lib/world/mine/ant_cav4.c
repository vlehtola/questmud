#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET set_not_out(1);

THREE_EXIT("world/mine/ant_cav7", "east",
	 "world/mine/ant_ca12", "north",        
	 "world/mine/ant_cav3", "south",        
	 "Ant cave",
	 "You are walking in a huge ant nest.\n" +
	 "The ceiling looks very solid and must have been done by ants.\n" + 
	 "You can see, because there is some strange light\n" + 
	 "coming from the rocks.\n", 3)
