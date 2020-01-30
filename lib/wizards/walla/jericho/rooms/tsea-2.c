inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/tsea-2");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/walla/jericho/rooms/tsea-1");
  add_exit("north","wizards/walla/jericho/rooms/tsea-3");
  short_desc = "On Tsea street";
  long_desc =
"You area standing on Tsea street, which is one of the main roads of Jericho.\n" +
"This road follows the eastern citywall, and is partly shrouded by it.\n" +
"The road is covered with dust, and is not paved like the bigger streets in the\n" +
"town.\n";
}
