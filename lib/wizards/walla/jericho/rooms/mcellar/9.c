
inherit "room/room";
 
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/nomap");
   return 1;
}
reset(arg) {
 
  add_exit("south","/wizards/walla/jericho/rooms/mcellar/10");
  add_exit("north","/wizards/walla/jericho/rooms/mcellar/8");
  short_desc = "In a faintly lit cavern";
  long_desc =
"You are in a faintly lit cavern, deep beneath the city. It looks as\n" +
"if the place has been here for some while. The air smells of sulphur and death,\n" +
"and the ground is covered with red coloured dust. Some water seems to be sippring\n" +
"through the limestone walls.\n";
}
