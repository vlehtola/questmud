
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor leads deeper into the monastery. The floor and walls are cracked and dust covers the benches lining the corridor which were probably made for some ancient monks to rest on.\n";
 add_exit("southwest",DIR+"room_11_9.c");
 add_exit("north",DIR+"room_12_7.c");
    set_light(1);
  }
}
