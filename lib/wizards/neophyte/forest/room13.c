inherit "room/room";
inherit "room/door";

int door_number;

reset(arg) {
  if (arg) { return; }
  short_desc = "Front of beach house";
  long_desc = "You are standing in a small open space in the middle of the beach,\n"+
              "just in front of you is a large building made of wood, the beach house.\n";
  add_exit("west", "/wizards/neophyte/forest/room12");
  add_exit("east", "/wizards/neophyte/forest/room14");
  door_reset();
  door_number = 1;
  set_door_label("wooden door",1);
  set_door_dir("south", "/wizards/neophyte/forest/house1", 1);
  set_door_link("/wizards/neophyte/forest/house1", 1);
  set_door_code(700, 1);
  set_locked(0, 1);
}

init() {
  ::init();
  door_init();
}
