
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor seems to be leading into some kind of living quarters.\n";
 add_exit("east",DIR+"room_9_4.c");
 add_exit("southwest",DIR+"room_7_5.c");
 add_exit("west",DIR+"room_7_4.c");
    set_light(1);
  }
}
