inherit "room/room";

reset(arg) {
  add_exit("north", "swa3f");
  add_exit("west", "swa4e");
  short_desc = "swamp";
  long_desc = "swamp 4 f.\n";
}

remexit() {
  remove_exit("north");
  tell_room(this_object(), "exitti meni\n");
}

addexit() {
  add_exit("north", "swa3f");
  tell_room(this_object(), "exitti tuli\n");
}