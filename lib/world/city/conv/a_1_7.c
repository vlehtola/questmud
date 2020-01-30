#include "room.h"

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
   if(random(10) && !present("citizen")) {
    move_object(clone_object("/world/monsters/citizen.c"),this_object());
   }

        return 0;
   }
   cat("/world/city/map");
   return 1;
}

TWO_EXIT("world/city/diamond6","north",
          "world/city/diaeme3","east",
"On the southern part of Diamond street",
"########### You are on Diamond street running north-east. There is a small\n" +
"# W |  Ps # street to Emerald street east of here. Most of the rich people\n" +
"# W *--+--# of Duranghom live along Diamon street. The large city wall\n" +
"# WWWWWWWW# rises very high over your head, as the city does not want to\n" +
"########### have any unexpected visitors. The Mainstreet of Duranghom is\n" +
"located a little north of here. You notice the south wall just south from\n" +
"this spot. All kinds of shops are scattered along this famous street.\n",3)

