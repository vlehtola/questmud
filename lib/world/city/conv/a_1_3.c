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

THREE_EXIT("world/city/diamond2","north",
          "world/city/diamond4","south",
	  "world/city/diaeme2","east",
"On the central part of Diamond street",
"########### You are on Diamond street running north-south next to\n" + 
"# W |     # the west wall. This street is home to most of the richest\n" +
"# W *--+--# people of Duranghom. The large city wall rises very high\n" + 
"# W |  A  # over your head, as the city does not want to have any \n" +
"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
"just south of here. You notice the north wall far away in the north.\n" + 
"All kinds of shops are scattered by the sides of this street.\n",3)

