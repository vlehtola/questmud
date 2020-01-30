
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor seems to be leading into some kind of living quarters.\n";
 add_exit("southeast",DIR+"room_13_7.c");
 add_exit("northeast",DIR+"room_13_5.c");
    set_light(1);
  }
}
