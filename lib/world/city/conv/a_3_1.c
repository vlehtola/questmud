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

TWO_EXIT("world/city/emerald2","south",
          "world/city/diaeme1","west",
"On the northern part of Emerald street",
"########### You are on Emerald street running north-west. There is a small\n" + 
"#WWWWWWWW # street leading to Diamond street west of here. The most of the\n" +
"#--+--* W # rich people of Duranghom live along Emerald street. The large\n" + 
"#     | W # city walls rise very high over your head, as the city does not\n" +
"########### want to have any unexpected visitors. The Mainstreet of Duranghom\n" +
"is located far away in south of here. The large north wall is just next to\n" + 
"you as the north-east wall. All kinds of shops are scattered by the sides of\n" +
"this street.\n",3)

