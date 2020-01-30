inherit "room/room";
inherit "room/door";

reset(arg) {
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
