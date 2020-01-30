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

THREE_EXIT("world/city/emerald2","north",
          "world/city/emerald4","south",
          "world/city/diaeme2","west",
"On the central part of Emerald street",
"########### You are on Emerald street, next to a small street which leads\n" + 
"#    |    # to Diamond street. This street is home to most of the rich\n" +
"#-+--*    # people of Duranghom. The Mainstreet of Duranghom is located\n" + 
"# A  |    # some distance in south from here. This old street has all\n"+
"########### kinds of shops scattered to each side of the street.\n",3)

