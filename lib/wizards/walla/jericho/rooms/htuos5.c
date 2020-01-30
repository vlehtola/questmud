inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/htuos5");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit3");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/walla/jericho/rooms/htuos4");
  add_exit("north","wizards/walla/jericho/rooms/tsea4");
  add_exit("southeast","wizards/walla/jericho/rooms/towers/se1");
  short_desc = "At the crossing of Htuos street and Tsea street";
  long_desc =
"You area standing at the crossing of Htuos street and Tsea street.\n" +
"You are in the southeastern corner of the city, and to the southeast, you\n" +
"can see a tower. The road north follows the city wall and stretches for\n" +
"for the whole length of the town.\n";
 
}

