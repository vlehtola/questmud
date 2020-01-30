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
   cat("/world/city/mapsor/");
   return 1;
}

TWO_EXIT("world/city/diamond7","north",
          "world/city/diaeme4","east",
"On the southern part of Diamond street",
"########### You are on Diamond street running north-south. There is a small\n" + 
"# W |     # street to Emerald street east of here. Most of the rich people\n" +
"# W *--+--# of Duranghom live. The large city wall rises very high\n" + 
"# WWWWWWWW# over your head, as the city does not want to have any \n" +
"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
"far north of here. The south wall runs next to you in the south.\n" + 
"Allkinds of shops are scattered along this famous street.\n",3)

