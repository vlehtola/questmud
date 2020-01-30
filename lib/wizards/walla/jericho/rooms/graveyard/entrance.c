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
 
  add_exit("north","/wizards/walla/jericho/rooms/graveyard/14");
  add_exit("south","/wizards/walla/jericho/rooms/ispep-1");
  short_desc = "entrance to a foggy graveyard";
  long_desc =
"You have entered a quiet area of the city, the graveyard. You are\n" +
"standing on a gravel path, leading towards the graves. A small fog\n" +
"lies a few feet of the ground, and the air has suddenly become just \n" +
"slightly colder.\n";
 
 
}
 
 
