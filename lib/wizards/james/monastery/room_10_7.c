
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "Entrance to the inner chambers";
    long_desc = "A small intersection of corridors which lead into the inner chambers of the monastery.\n";
 add_exit("southeast",DIR+"room_11_8.c");
 add_exit("southwest",DIR+"room_9_8.c");
 add_exit("north",DIR+"room_10_6.c");
    set_light(1);
  }
}
