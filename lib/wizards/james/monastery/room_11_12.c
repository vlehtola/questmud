
#include "dir.h"
inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    short_desc = "Living quarters";
    long_desc = "This room looks like it was used as a living quarters. A wooden bed is in the corner of the room and a small altar takes almost half of the space left in the room. The room looks very simple, suitable for a monk.\n";
 add_exit("northwest",DIR+"room_10_11.c");
    set_light(1);
  }
}
