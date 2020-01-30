
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "A side corridor";
    long_desc = "This side corridor seems to be leading into some kind of storage area. There is lots of junk lying around in the corridor.There are stairs leading slightly downwards in the eastern wall.\n";
 add_exit("east",DIR+"room_9_5.c");
 add_exit("northwest",DIR+"room_7_4.c");
    set_light(1);
  }
}
