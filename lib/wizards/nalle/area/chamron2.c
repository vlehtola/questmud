#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
}

FOUR_EXIT("wizards/nalle/area/inn","west",
"wizards/nalle/area/path","east",
"wizards/nalle/area/chamron3","north",
"wizards/nalle/area/entrance","south",
"Southern part of the City of Chamron",
"You are currently in the southern part of the City of Chamron. There\n" +
"are many people of various races spending their time in this crowded\n" +
"part of the town. To the west seems to be an inn of some kind. The\n" +
"entrance into the city lies in south. A path to your east seems to\n" + 
"lead to a massive black tower in the eastern side of the city.\n", 3)

