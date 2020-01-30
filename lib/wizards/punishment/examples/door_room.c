/* This room must be loaded before the room at the other side of the door,
or the codes will be messed out. (because of the random_door_code() call) */

inherit "room/room";
inherit "room/door";

reset(arg) {
  if (arg) { return; }
  short_desc = "Door room";
  long_desc = "You are in the door room.\n";

  add_exit("south", "/wizards/onarion/workroom");
  set_door_dir("north", "/doc/examples/door_room2");
  set_door_link("/doc/examples/door_room2");
  random_door_code();
  set_door_desc("bronze ");
}

init() {
  ::init();
  door_init();
}
