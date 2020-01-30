
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "Inner chambers";
    long_desc = "These are the inner chambers of the now abandoned monastery. They are used as offices by the higher ranking monks.\n";
 add_exit("northeast",DIR+"room_10_7.c");
    set_light(1);
  }
}
