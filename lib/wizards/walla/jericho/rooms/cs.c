
inherit "room/room";
 
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/cs");
   return 1;
}
reset(arg) {
 
  add_exit("north","/wizards/walla/jericho/rooms/ujar-1");
  add_exit("south","/wizards/walla/jericho/rooms/ujar1");
  add_exit("west","/wizards/walla/jericho/rooms/ispep-1");
  add_exit("east","/wizards/walla/jericho/rooms/ispep1");
  short_desc = "Grand place";
  long_desc =
"You are standing in the middle of the city. The walls can be seen\n" +
"in the distance. You notice that the ground has been newly paved\n" +
"with white marble from distant lands. A thing that strikes you, is\n" +
"the lack of animals in the town. The commotion in the city has not\n"
"quite yet started, as people have only just started settling.\n";
 
 
}
 




