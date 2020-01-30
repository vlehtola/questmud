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

FOUR_EXIT("world/city/emerald8","south",
          "world/city/emerald6","north",
          "world/city/ice4","east",
          "world/city/diaeme3","west",
"On the central part of Emerald street",
"########### You are on Emerald street running across Ice street, which\n" +
"# Ps |  L # starts from here. This street is home to most of the rich\n" +
"#-+--*--+-# people of Duranghom. The Mainstreet of Duranghom is located\n" +
"#WWW |    # some distance in north from here. This old street has all\n" +
"########### kinds of shops scattered to each side of the street. There\n" +
"is also a street leading east to Diamond street.\n",3)

