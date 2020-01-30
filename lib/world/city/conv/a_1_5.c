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

FOUR_EXIT("world/city/mainstr3","east",
          "world/city/mainstr1","west",
          "world/city/diamond4","north",
          "world/city/diamond6","south",
"On western part of Mainstreet",
"########### This is een Diamond\n" + 
"#  T *    # street. This old and large street is usually crowded\n" +
"# TT |  N # with merchants and travellers that wander across this\n" + 
"# ==-+--+-# big city, busily looking for a place to stay for the\n" +
"########### night and food for their long travels. To the west is\n" +
"the western gate and to the east the central square. This street\n" + 
"draws a line across the city, dividing it in north and south parts.\n" +
"The houses to the north seem better built.\n",3)

