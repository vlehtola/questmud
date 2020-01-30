
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor seems to be leading into some kind of living quarters.\n";
 add_exit("east",DIR+"room_14_7.c");
 add_exit("northwest",DIR+"room_12_6.c");
 add_exit("south",DIR+"room_13_8.c");
    set_light(1);
  }
}
