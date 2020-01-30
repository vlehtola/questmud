inherit "room/room";
object mob,mob2;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }

  if(!mob2) {
  mob2 = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob2, this_object()); }
{
  if(arg) return;

  add_exit("west", "katu40.c");
  add_exit("east", "katu42.c");
  add_exit("south", "katu36.c");
  add_exit("north", "katu48.c");
  
  short_desc = "The crossing";
  long_desc = ""
"###########       You are at the crossing of the Dalvur and Mormain street.\n"+
"#    V            In the north you can see a wooden door of the warehouse.\n"+
"#  A |            The odours of freshly baked bakery products coming from\n"+
"#+---*-9-+-       the west fills your nose. The street of Dalvur continues\n"+ 
"#| B |            to north and south, and Mormain leads to east and west.\n"+
"#|S W| ####\n";

  set_light(2);
}
}
