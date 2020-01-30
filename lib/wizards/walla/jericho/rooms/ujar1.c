
inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ujar1");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/walla/jericho/rooms/cs");
  add_exit("south","wizards/walla/jericho/rooms/ujar2");
  add_exit("east","wizards/walla/jericho/rooms/bazaar/wentrance");
  add_exit("west","jennashop");
  short_desc = "On Ujar street";
  long_desc =
"You are standing on Ujar street, one of the main roads in Jericho.\n" +
"Further north is the Grande Place, which connects the two major\n" +
"roads in the city. To the east is the bazaar, which, after long and\n" +
"difficult times is almost abandoned.\n";
 
}





