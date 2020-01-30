
inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ujar2");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/ujar1");
  add_exit("south","wizards/walla/jericho/rooms/ujar3");
  short_desc = "On Ujar street";
  long_desc =
"You area standing on Ujar street, wihch is one of the main roads of Jericho.\n" +
"The road has been recently paved, and you can see some of the old cobblestones\n" +
"still lying in piles, at the side of the road.\n";
 
}
