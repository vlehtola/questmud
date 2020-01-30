inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "The playroom";
  long_desc = "This is the place where the fruitgame machine is located.\n";
  add_exit("south", "/world/casino/middleroom");
  move_object(clone_object("/world/casino/onehand"), this_object());
}
