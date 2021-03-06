inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/htorn-2");
   return 1;
}
object monster;
 
reset(arg) {
  
  add_exit("east","wizards/walla/jericho/rooms/htorn-1");
  add_exit("west","wizards/walla/jericho/rooms/htorn-3");
  short_desc = "On Htorn street";
  long_desc =
"You area standing on Htorn street, which is one of the main roads of Jericho.\n" +
"This road follows the northern citywall, and is partly shrouded by it.\n" +
"The road is covered with dust, and is not paved like the bigger streets in the\n" +
"town.\n";
}
