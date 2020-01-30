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

FOUR_EXIT("world/city/emerald1","north",
          "world/city/emerald3","south",
	  "world/city/fire2","east",
	  "wizards/celtron/sinrad/guard_hq","west",
"On the northern part of Emerald street",
"########### You are on Emerald street crossing Fire Street located\n" + 
"#    | WWW# east of here. This street is home to most of the rich\n" +
"#  Gu*--+-# people of Duranghom. The large city wall rises very high\n" + 
"#    |    # over your head, as the city does not want to have any \n" +
"########### unexpected visitors. The Mainstreet of Duranghom is\n" +
"located much south of here. You notice a wall away in the north. The\n" + 
"cityguards' headquarters is west from here.\n",3)

