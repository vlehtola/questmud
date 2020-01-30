
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor seems to be leading into some kind of living quarters.\n";
 add_exit("southeast",DIR+"room_11_12.c");
 add_exit("northwest",DIR+"room_9_10.c");
 add_exit("southwest",DIR+"room_9_12.c");
 add_exit("south",DIR+"room_10_12.c");
 add_exit("northeast",DIR+"room_11_10.c");
    set_light(1);
  }
}
