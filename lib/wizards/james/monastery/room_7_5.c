
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "This corridor seems to be leading into some kind of living quarters.\n";
 add_exit("southeast",DIR+"room_8_6.c");
 add_exit("west",DIR+"room_6_5.c");
 add_exit("northeast",DIR+"room_8_4.c");
    set_light(1);
  }
}
