inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/htorn-5");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/htorn-4");
  add_exit("south","wizards/walla/jericho/rooms/tsew-3");
  add_exit("northwest","wizards/walla/jericho/rooms/towers/nw1");
  short_desc = "At the crossing of Htorn street and Tsew street";
  long_desc =
"You area standing on Htorn street, which is one of the main roads of Jericho.\n" +
"This road follows the northern citywall, and is partly shrouded by it.\n" +
"The road is covered with dust, and is not paved like the bigger streets in the\n" +
"town. To the south, you can see Tsew street.\n";
}

