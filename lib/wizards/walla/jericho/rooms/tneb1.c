inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/tneb1");
   return 1;
}
object monster;
 
reset(arg) {
 
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/tsea-3");
  add_exit("north","wizards/walla/jericho/rooms/leblair/entrance");
  add_exit("west","wizards/walla/jericho/rooms/tneb2");
  short_desc = "On Tneb street";
  long_desc =
"You are standing on a small dust path, leading to destinations unknown.\n" +
"Tneb street is a small street, made by just walking there. Judging from the\n" +
"dust on the street, it seems to have been unused for a while, but somehow\n" +
"you feel, that there is a bigger truth to be found.\n";
}
