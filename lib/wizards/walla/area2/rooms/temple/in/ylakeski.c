inherit "room/room";
 
object dragon,praying;

  reset(arg) {
  
  if(!dragon) {
    dragon = clone_object("wizards/walla/area2/stuph/statue");
    move_object(dragon, this_object()); }
 
  if(!praying) {
    praying = clone_object("wizards/walla/area2/mobs/praying");
    move_object(praying, this_object()); }

  add_exit("west","/wizards/walla/area2/rooms/temple/in/ylavasen");
  add_exit("east","/wizards/walla/area2/rooms/temple/in/ylaoikea");
  add_exit("south","/wizards/walla/area2/rooms/temple/in/keski");
  add_exit("southeast","/wizards/walla/area2/rooms/temple/in/oikeakeski");
  add_exit("southwest","/wizards/walla/area2/rooms/temple/in/vasenkeski");
  short_desc = "A platform built on top of the stairs";
  long_desc =
"You have come to a place of peace and quiet. Before you stands a huge statue\n" +
"of a blue dragon. The place is so quiet, that you can hear the flames from\n" +
"the candles, flickering in the chandeliers around you.\n" +
"Perhaps you should respect this silence also.\n";
 
}

