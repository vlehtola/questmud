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

THREE_EXIT("world/city/diamond7","west",
          "world/city/emerald7","east",
          "guilds/psi/psiguild","north",
"On a street leading from Diamond street to Emerald Street",
"########### You are on a small crossing street running from Diamond\n" +
"# |  Ps | # street to Emerald street. This street is so small it doesn't\n" +
"# +--*--+ # even have a name. The old buildings around you rise high over\n" +
"#WWWWWW | # your head, as you are located in the richest part of the city\n" +
"########### of Duranghom. \n",3)

