/* This room must be loaded before the room at the other side of the door,
or the codes will be messed out. (because of the random_door_code() call) */

inherit "room/room";
inherit "room/door";

reset(arg) {
  if (arg) { return; }
  short_desc = "Door room2";
  long_desc = "You are in the 2nd door room.\n";

  door_reset();
  set_door_label("metal door",1);
  set_door_dir("south", "/doc/examples/door_room",1);
  set_door_link("/doc/examples/door_room",1);
  set_door_code(66, 1);
  set_locked(0, 1);
}


init() {
  ::init();
  door_init();
}
