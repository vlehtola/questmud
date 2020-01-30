inherit "room/room";
inherit "room/door";

reset(arg) {
  short_desc = "Door room 2";
  long_desc = "You are behind the door.\n";

  add_exit("north", "/wizards/onarion/workroom");
  set_door_dir("south", "/doc/examples/door_room");
  set_door_link("/doc/examples/door_room");
  random_door_code();
  set_door_desc("bronze ");
}

init() {
  ::init();
  door_init();
}
