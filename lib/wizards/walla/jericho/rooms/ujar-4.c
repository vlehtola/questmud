inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ujar-4");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/htorn1");
  add_exit("west","wizards/walla/jericho/rooms/htorn-1");
  add_exit("north","wizards/walla/jericho/rooms/towers/n1");
  add_exit("south","wizards/walla/jericho/rooms/ujar-3");
  short_desc = "At the crossing of Ujar Street and Htorn street";
  long_desc =
"You area standing on Htorn street, which is one of the main roads of Jericho.\n" +
"This road follows the eastern citywall, and is partly shrouded by it.\n" +
"The road is covered with dust, and is not paved like the bigger streets in the\n" +
"town. To the north you can see the northern guardtower.\n";
}
