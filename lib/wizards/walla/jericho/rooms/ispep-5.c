inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ispep-5");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/ispep-4");
  add_exit("west","wizards/walla/jericho/rooms/towers/w1");
  add_exit("north","wizards/walla/jericho/rooms/tsew-1");
  add_exit("south","wizards/walla/jericho/rooms/tsew1");
  short_desc = "At the crossing of Tsew street and Ispep street";
  long_desc =
"You area standing on the crossing of Tsew street and Ispep street\n" +
"To the west you can see a huge guardtower, with an entrance in the city wall.\n" +
"The old observatory that once used to lie here seems to have been torn apart\n" +
"and the ground is now covered with a thick wall.\n";
}
