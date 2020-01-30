inherit "room/room";
inherit "room/door";
 
reset(arg) {
  if (arg) { return; }
  short_desc = "joojoo";
  long_desc = "tanne tulee hiano desci.\n";
  add_exit("north","/wizards/walla/area2/rooms/ricefield/cave/2");
  door_reset();
  set_door_label("metal door",1);
  set_door_dir("south", "/wizards/walla/area2/rooms/ricefield/28",1);
  set_door_link("/wizards/walla/area2/rooms/ricefield/28",1);
  set_door_code(66, 1);
  set_locked(0, 1);
}
 
 
init() {
  ::init();
  door_init();
}

