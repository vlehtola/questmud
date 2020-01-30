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
	 "out: 94 113", "north",
	 "out: 94 113", "south",
	 "out: 94 113", "west",
	 "out: 94 113", "east",
"Entrance to the Village of Chamron.",
"You have finally arrived to the gates of Chamron, a small village\n" +
"built near the fortifications of the Dequan Knights. The city\n" +
"does not seem extremely luxurious, but at least it is a safe from\n" +
"barbarian attacks. It is also known for its homelike atmosphere.\n" +
"Large oaks and birches surround you and a river can be heard\n" +
"flowing somewhere nearby.\n", 5)
