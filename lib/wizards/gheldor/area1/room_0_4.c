inherit "room/room";
#include "/wizards/gheldor/include/default.h"

reset(arg) {
  if(arg) return;
  short_desc = "Inside the Mystical Forest";
  long_desc = AREA_D->get_long("mforest");
  set_light(1);
  AREA_D->get_monsters("mforest",4,this_object());
  AREA_D->get_exits(this_object());
}
