inherit "room/room";

reset(arg) {
  add_exit("north", "swa1b");
  add_exit("west", "swa2a");
  add_exit("east", "swa2c");
  short_desc = "swamp";
  long_desc = "swamp 2 b.\n";
}

remexit() {
  remove_exit("west");
  tell_room(this_object(), "exitti meni\n");
}

addexit() {
  add_exit("west", "swa2a");
  tell_room(this_object(), "exitti tuli\n");
}