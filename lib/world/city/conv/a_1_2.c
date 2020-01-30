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

TWO_EXIT("world/city/diamond1","north",
          "world/city/diamond3","south",
"On the northern part of Diamond street",
"########### You are on Diamond street running north-south next to\n" + 
"# W |     # the west wall. This street is home to most of the richest\n" +
"# W *   Gu# people of Duranghom. The large city wall rises very high\n" + 
"# W |     # over your head, as the city does not want to have any \n" +
"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
"much south of here. You notice the north wall some distance away in\n" + 
"the north. All kinds of shops are scattered by the sides of this street.\n",3)

