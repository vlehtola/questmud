
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "In a corridor";
    long_desc = "A corridor leading into the monastery. There are some stairs leading upwards to the north and two corridors, leading northwest and northeast.\n";
 add_exit("northwest",DIR+"room_9_4.c");
 add_exit("north",DIR+"room_10_4.c");
 add_exit("south",DIR+"room_10_6.c");
 add_exit("northeast",DIR+"room_11_4.c");
    set_light(1);
  }
}
