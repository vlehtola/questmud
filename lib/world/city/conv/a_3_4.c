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

THREE_EXIT("world/city/emerald3","north",
          "world/city/mainstr3","south",
          "world/shops/weapon_shop","west",
"On the central part of Emerald street",
"########### You are on Emerald street next to the Mainstreet street of\n" + 
"# A  |    # Duranghom. This street is home to most of the rich\n" +
"#  We*    # people of Duranghom. The Mainstreet of Duranghom is located\n" + 
"#    |    # just south of here. This old street has all kinds of shops\n" +
"########### scattered to each side of the street. The old-traditioned\n" +
"weapon smith's shop is located just west of here.\n",3)

