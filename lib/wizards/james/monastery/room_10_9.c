
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "An intersection";
    long_desc = "Three corridors branch out from this dimly lit chamber. The eastern and western ways seem to lead deeper into the monastery and the southern corridor seems to lead outwards.\n";
 add_exit("east",DIR+"room_11_9.c");
 add_exit("south",DIR+"room_10_10.c");
 add_exit("west",DIR+"room_9_9.c");
    set_light(1);
  }
}
