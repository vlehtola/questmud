
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In the halls of the monastery";
    long_desc = "Rays of light shine down from the cracks in the ceiling, illuminating the dusty floor. The walls are cracked and torn tapestries hang from them.\n";
 add_exit("southeast",DIR+"room_11_11.c");
 add_exit("north",DIR+"room_10_9.c");
    set_light(1);
  }
}
