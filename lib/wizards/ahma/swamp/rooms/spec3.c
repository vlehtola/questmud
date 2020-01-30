inherit "room/room";
int third;

reset(arg) {
  add_exit("south", "swa1b");
  short_desc = "special";
  if(!third) { long_desc = "special 3.\n"; }
  else { long_desc = "special 3 thirddone.\n"; }
}

thirddone() {
  tell_room(this_object(), "A small hill rises up from the ground to your north.\n");
  third = 1;
}