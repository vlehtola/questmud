#include "dir.h"
inherit "room/room";

reset(arg) {
  if(!present("woman"))
move_object(clone_object(DIR+"woman"),this_object());
if(!arg)
  {
    short_desc = "Entrance hall of the monastery";
    long_desc = "This is a huge entrance hall to what seems to be a monastery of monks. The walls are covered\n"+
                "with complicated religious symbols. Some light shines in from small colourful windows,\n"+
"illuminating the place with colourful rays.\n";
    add_exit("northwest",DIR+"room_11_11.c");
    set_light(1);
  }
}
