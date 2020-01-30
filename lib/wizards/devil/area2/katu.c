#include "room.h"

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   
   cat("/wizards/devil/area2/map");
   return 1;
}

THREE_EXIT("world/city/cs","west",
          "world/city/gold2","east",
          "guilds/fighter/fighter","south",
"On the central part of king street",
"##=##\n"+
"--*-- Kings road, just inside the city gate of Bhrech. In the\n"+
".I|.. distance you can see the royal castle south of here. To the\n"+
".B|O. west a sign is hanging out from a building.\n"+
"+-+-+\n", 3)
