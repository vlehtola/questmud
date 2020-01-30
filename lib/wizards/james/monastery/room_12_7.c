
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor leads deeper into the monastery. The floor and walls are cracked and dust covers the benches lining the corridor which were probably made for some ancient monks to rest on.\n";
 add_exit("northwest",DIR+"room_11_6.c");
 add_exit("south",DIR+"room_12_8.c");
    set_light(1);
  }
}
