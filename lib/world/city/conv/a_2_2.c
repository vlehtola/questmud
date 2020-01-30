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

THREE_EXIT("world/city/diamond3","west",
          "world/city/emerald3","east",
          "world/shops/armour_shop","south",
"On a street leading from Diamond street to Emerald Street",
"########### You are on a small crossing street running from Diamond\n" + 
"# |     | # street to Emerald street. This street is so small it doesn't\n" +
"# +--*--+ # even have a name. The old building around you rise high over\n" + 
"# |  A  | # your head, as you are located in the richest part of the city\n" +
"########### of Duranhom. The city Armourer is located south of here.\n",3)
