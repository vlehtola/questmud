#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "river";
    items[1] = "The small river of Chamron, the Feuve, is flowing near the city walls.";
}
FIVE_EXIT(
"wizards/nalle/area/chamron2","enter",
	 "out: 89 105", "north",
	 "out: 89 105", "south",
	 "out: 89 105", "west",
	 "out: 89 105", "east",
"Entrance to the Village of Chamron.",
"You have finally arrived to the gates of Chamron, a small village\n" +
"built near the fortifications of the Dequan knights. The city\n" +
"does not seem extremely luxurious, but at least it is safe from \n" +
"barbarian attacks, and has a homelike atmosphere. Large oaks \n" +
"and birches surround you, and you hear a river flowing nearby. \n", 5)
