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

TWO_EXIT("world/city/diamond1","west",
          "world/city/emerald1","east",
"On a street leading from Diamond street to Emerald Street",
"########### You are on a small crossing street running from Diamond\n" + 
"#WWWWWWWWW# street to Emerald street. This street is so small it does not\n" +
"# +--*--+ # even have a name. The old and large north wall rises very high\n" + 
"# |     | # over your head, as the city does not want to have any \n" +
"########### unexpected visitors.\n",3)

