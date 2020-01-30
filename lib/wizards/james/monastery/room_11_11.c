#include "dir.h"
inherit "room/room";

reset(arg) {
if(!present("monk")) {
move_object(clone_object(DIR+"monk4"),this_object());
move_object(clone_object(DIR+"monk_evil4"),this_object());
}
if(!arg) {
    short_desc = "The front doors of the monastery";
    long_desc = "This corridor leads to huge oaken double-doors which are reinforced with steel bands.\n"+
"Some benches line the walls, it seems they are made for people who are waiting to get\n"+
"inside the monastery. The corridor is very high and a huge chandelier hanging from the\n"+
"ceiling illuminates this place very brightly.\n";
    add_exit("southeast",DIR+"room_12_12.c");
    add_exit("northwest",DIR+"room_10_10.c");
    set_light(1);
  }
}
