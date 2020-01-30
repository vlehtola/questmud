inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/tsew2");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/tsew1");
  add_exit("south","wizards/walla/jericho/rooms/tsew3");
  short_desc = "On Tsew street";
  long_desc =
"You area standing on Tsew street, which is the western road in Jericho.\n" +
"This road follows the western citywall, which can been seen to your left.\n" +
"The road is covered with dust.\n";
}



