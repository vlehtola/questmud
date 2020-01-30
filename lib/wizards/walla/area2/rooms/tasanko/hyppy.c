inherit "room/room";
int deeth;
 
reset(arg) {
  add_exit("north","/wizards/walla/area2/rooms/tasanko/cs");
  short_desc = "Standing on a platform";
  long_desc =
"You had no idea the mountains could look this beautiful. All around you,\n" +
"you see mountaintops bathing in a sea of clouds, hanging below you.\n" +
"You are standing on what appears to be a viewing ledge, to where monks\n" +
"retire to watch the sun set. If you streched out your hands, and closed\n" +
"your eyes, it would almost feel like flying. You feel you are the king\n" +
"of the world. You can return by leaving the scene.\n";
 
  items = allocate(4);
  items[0] = "ledge";
  items[1] = "A ledge on which you can stand...";
 
}
init() {
  ::init();
  add_action("leave", "leave");
  add_action("jump", "jump");
}
leave(str) {
  if((str) == "scene") {
  write("You sigh, turn around quickly and leave the view behind.\n");
  say( "turns with a sigh, and leaves to the north.\n");
  move_object(this_player(), "/wizards/walla/area2/rooms/tasanko/cs");
  return 1;
 }
}
 
jump(str) {
  if((str) == "void") {
  write("You decide to take the leap of faith, and jump into the void. It almost feels like you can fly.\n");
  say(this_player()->query_name()+" jumps over the ledge and soars into the sky below.\n");
  deeth = 21000;
  this_player()->reduce_hp(deeth);
  return 1;
 
 }
}
