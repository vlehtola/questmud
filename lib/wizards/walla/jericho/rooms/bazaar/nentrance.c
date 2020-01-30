inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/map");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/bazaarguard");
    move_object(monster, this_object());
  }
 
 
  if(arg) return;
  add_exit("south","wizards/walla/jericho/rooms/bazaar/ylavasen");
  add_exit("north","wizards/walla/jericho/rooms/ispep1");
  short_desc = "Entrance of the bazaar";
  long_desc =
"You have arrived at the entrance of the bazaar of Jericho,\n" +
"which is the main place, where people socialize these days.\n" +
"The bazaar does not have as many shopkeepers as it used to,\n" +
"but prosperity is slowly returning to these parts of the\n" +
"world aswell.\n";
 
}
