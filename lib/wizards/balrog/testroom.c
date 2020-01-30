#include <ansi.h>
inherit "room/room";

reset(status arg) 
{
  if(arg) return;
  add_exit("return","/wizards/kuaffel/workroom");
  short_desc = "Test Room";
  long_desc = "This room has blueprints, reference books and crumpled papers all over the place.\n"+
       "A big waste basket is placed in the middle of the room. Filled to the brim.\n";
  property = allocate(1);
  property[0] = "no_summon";

  set_light(3);
}

init() 
{
  ::init();
}
