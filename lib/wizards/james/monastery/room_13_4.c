
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "A side corridor";
    long_desc = "This side corridor seems to be leading into some kind of storage area. There is lots of junk lying around in the corridor.\n";
 add_exit("southwest",DIR+"room_12_5.c");
 add_exit("west",DIR+"room_12_4.c");
    set_light(1);
  }
}
