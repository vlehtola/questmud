
inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ujar-2");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/ujar-3");
  add_exit("south","wizards/walla/jericho/rooms/ujar-1");
  short_desc = "On Ujar street";
  long_desc =
"You area standing on Ujar street, which is one of the main roads of Jericho.\n" +
"The road goes from north to south, ans seems to have been just recently paved.\n" +
"Some old cobblestones are still lying in piles, at the side of the street.\n" +
"To the west, you can see the cemetary.\n";
}
 
