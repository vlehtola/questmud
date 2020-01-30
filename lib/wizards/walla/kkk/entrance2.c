#include "room.h" 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
TWO_EXIT("world/city/inn", "north",
         "wizards/walla/area/jercs", "south",
         "At the entrance of a Klavern",
         "You are on a rocky road leading north and south.\n" +
         "Mountain sides rise high above you by both sides of the road.\n", 1)
 
extra_reset() {
  set_req("north");
 }
 
query_req() {
  if(this_player()->query_level() < 69 || this_player()->query_level() > 80 ||
        this_player()->query_race() == "sprite")
    write("A guard pops out, and throws you back to where you came from.\n");
    return 1;
  }
