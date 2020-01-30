inherit "room/room"; 
int deeth;
 
reset(arg) {
  short_desc = "In a well";
  long_desc =
"You are standing in a well.\n" +
"The water here is but up to your ankles. There is something funny about this place\n" +
"and you can feel a smell you don't recall smelling anywhere else in this realm.\n" +
"You seem to be curious where that water is flowing, but you are afraid to swim anywhere\n" +
"near that torrent. The wisest thing to do would be to climb back up.\n";
 
  items = allocate(4);
  items[0] = "water";
  items[1] = "just water, flowing rapidly here.";
 
 }
init() {
  ::init();
  add_action("climb", "climb");
  add_action("swim", "swim");
}
climb(str) {
  if((str) == "well") {
  write("You climb back up the well to the place where you left.\n");
  say( "climbs back up the well, afraid to continue.\n");
  move_object(this_player(), "/wizards/walla/dl/rooms/xaktsaroth/wellroom");
  return 1;
 }
}
 
swim(str) {
   if((str) == "water") {
  write("You start swimming to the light, only to discover that you can't go back. You fall down a steep waterfall and...\n");
  say(this_player()->query_name()+" swims along the water, but doesn't notice that he can't come back. Wave bye bye...\n");
  deeth = 21000;
  this_player()->reduce_hp(deeth);
  return 1;
 
 }
}
