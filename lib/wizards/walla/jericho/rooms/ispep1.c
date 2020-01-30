inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ispep1");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/ispep2");
  add_exit("west","wizards/walla/jericho/rooms/cs");
  add_exit("south","wizards/walla/jericho/rooms/bazaar/nentrance");
  short_desc = "On Ispep street";
  long_desc =
"You area standing on Ispep street, which is one of the main roads of Jericho.\n" +
"The road has been recently paved, and you can see some of the old cobblestones\n" +
"still lying in piles, at the side of the road.\n";
}
