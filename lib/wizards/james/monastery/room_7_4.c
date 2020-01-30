
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "A side corridor";
    long_desc = "This side corridor seems to be leading into some kind of storage area. There is lots of junk lying around in the corridor.\n";
 add_exit("southeast",DIR+"room_8_5.c");
 add_exit("east",DIR+"room_8_4.c");
    set_light(1);
  }
}
