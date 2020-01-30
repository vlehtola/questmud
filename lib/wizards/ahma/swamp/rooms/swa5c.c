inherit "room/room";

reset(arg) {
  add_exit("north", "swa4c");
  add_exit("west", "swa5b");
  short_desc = "swamp";
  long_desc = "swamp 5 c.\n";
}

remexit() {
  remove_exit("north");
  tell_room(this_object(), "exitti meni\n");
}

addexit() {
  add_exit("north", "swa4c");
  tell_room(this_object(), "exitti tuli\n");
}