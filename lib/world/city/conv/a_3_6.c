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

THREE_EXIT("world/city/emerald7","south",
          "world/city/mainstr3","north",
          "guilds/mage/apprmage","west",
"On the central part of Emerald street",
"########### You are on Emerald street next to the Mainstreet street of\n" +
"# Ms |    # Duranghom. This street is home to most of the rich\n" +
"#  Mg*    # people of Duranghom. The Mainstreet of Duranghom is located\n" +
"# Ps |  L # just north of here. This old street has all kinds of shops\n" +
"########### scattered to each side of the street. A famous building, The\n" +
"Mages Guild, towers over you in the west.\n",3)

