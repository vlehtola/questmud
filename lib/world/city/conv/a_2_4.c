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

TWO_EXIT("world/city/diamond7","west",
          "world/city/emerald7","east",
"On a street leading from Diamond street to Emerald Street",
"########### You are on a small street running from Diamond street to\n" + 
"# |     | # Emerald street. This street is so small it doesn't even have\n" +
"# +--*--+ # a name. The large and old south wall rises high over your head,\n" + 
"#WWWWWWWWW# as the city does not want any unexpected visitors such as\n" +
"########### thieves.\n",3)

