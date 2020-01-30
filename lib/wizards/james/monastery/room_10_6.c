
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "A shady intersection";
    long_desc = "This intersection divides into four exits. The eastern and western corridors seem to lead outwards while the northern and southern exits seem to lead deeper into the abandoned monastery. The doorway to the south has some strange inscriptions around it.\n";
 add_exit("east",DIR+"room_11_6.c");
 add_exit("north",DIR+"room_10_5.c");
 add_exit("south",DIR+"room_10_7.c");
 add_exit("west",DIR+"room_9_6.c");
    set_light(1);
  }
}
