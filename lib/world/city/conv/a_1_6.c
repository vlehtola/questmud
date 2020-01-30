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

THREE_EXIT("world/city/diamond7","south",
          "world/city/mainstr1","north",
	  "guilds/library/hallway", "east",
"On the central part of Diamond street",
"########### You are on Diamond street running north-south next to\n" +
"#TT |  Ms # the west wall. This street is home to most of the richest\n" +
"# T *Lb   # people of Duranghom. The large city wall rises very high\n" +
"# W |  Ps # over your head, as the city does not want to have any \n" +
"########### unexpected visitors. The Mainstreet of Duranghom is located\n" +
"just north of here. You notice the the south wall away in south.\n", 3)

