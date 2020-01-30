
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor seems to be leading into some kind of living quarters.\n";
 add_exit("east",DIR+"room_14_8.c");
 add_exit("southwest",DIR+"room_12_9.c");
 add_exit("north",DIR+"room_13_7.c");
    set_light(1);
  }
}
