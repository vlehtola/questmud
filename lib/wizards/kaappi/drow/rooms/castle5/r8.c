inherit "room/room";
inherit "room/door";

reset(arg) {
  
  add_exit("south", "r6.c");
  add_exit("southwest", "r5.c");
  add_exit("southeast", "r7.c");

  short_desc = "A hallway";
  long_desc = "You are standing in front of a small door.\n"+
              "Some loud voices can be heard from behind\n"+
              "it. There are two wooden sabres placed above\n"+
              "of the door. The entrance of this castle can be\n"+
              "seen far in the south.\n";
 
  set_light(1);

door_reset();
  set_door_label("wooden door",1);
  set_door_dir("north", "th.c",1);
  set_door_link("/wizards/kaappi/drow/rooms/castle5/th.c",1);
  set_locked(0, 1);
set_not_out();
}

init() {
  ::init();
  door_init();
}
