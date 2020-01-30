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

TWO_EXIT("world/city/diamond2","south",
          "world/city/diaeme1","east",
"On the northern part of Diamond street",
"########### You are on Diamond street running north-east. There is a small\n" + 
"# WWWWWWWW# street leading to Emerald street east of here. The richest people\n" +
"# W *--+--# of Duranghom live here. The large city walls rise very high\n" + 
"# W |     # over your head, as the city does not want to have any \n" +
"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
"far away in south of here. The large north wall is just next to you as is the\n" + 
"west wall. All kinds of shops are scattered by the sides of this street.\n",3)

