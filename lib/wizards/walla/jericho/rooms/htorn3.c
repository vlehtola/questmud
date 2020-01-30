inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/htorn3");
   return 1;
}
object monster;
 
reset(arg) {
  
  add_exit("east","wizards/walla/jericho/rooms/htorn4");
  add_exit("west","wizards/walla/jericho/rooms/htorn2");
  add_exit("south","wizards/walla/jericho/rooms/tneb2");
  short_desc = "At the crossing of Htorn street and Tneb street";
  long_desc =
"You area standing on Htorn street, which is one of the main roads of Jericho.\n" +
"This road follows the northern citywall, and is partly shrouded by it.\n" +
"The road is covered with dust, and is not paved like the bigger streets in the\n" +
"town.\n";
}
