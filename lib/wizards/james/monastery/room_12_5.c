
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "A side corridor";
    long_desc = "This side corridor seems to be leading into some kind of storage area. There is a lot of junk lying around in the corridor. There are stairs leading slightly downwards in the western wall.\n";
 add_exit("west",DIR+"room_11_5.c");
 add_exit("northeast",DIR+"room_13_4.c");
    set_light(1);
  }
}
