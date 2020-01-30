/* Questions? Ask Celtron */

inherit "room/room";
inherit "room/door";

int door_number;

reset(arg) {
  if (arg) { return; }
  short_desc = "Door room";
  long_desc = "You are in the door room.\n";

  door_reset();
  /* door number means that the below lines affect the 1st door in this room */
  door_number = 1;
  set_door_label("wooden door", door_number);
  set_door_dir("north", "/doc/examples/door_room2", door_number);
  set_door_link("/doc/examples/door_room2", door_number);
  /* door_code needs to match the key code */
  set_door_code(66, door_number);
  /* 0 is unlocked, 1 is locked */
  set_locked(0, door_number);
}


init() {
  ::init();
  door_init();
}
