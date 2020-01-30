inherit "/room/room";

reset(arg) {
  if (arg) return;
  set_not_out(1);
  set_light(3);

  add_exit("north", "/room/houses/rooms/house10_locker1");
  add_exit("south", "/room/houses/rooms/house10_locker2");
  add_exit("down", "/room/houses/rooms/house10");

  short_desc = "Second floor";
  long_desc =
"You are in the second floor. There is a window giving to the street.\n"+
"There is a wooden stairway leading down.\n";

  items = allocate(2);
  items[0] = "window";
  items[1] = 
"You can open the glass window easily from the inside. It gives to the\n"+
"street infront of the house. Maybe you could jump from it to the street.";

property = allocate(2);
property[0] = "no_kill";
property[1] = "no_summon";
}

init() {
  ::init();
  add_action("jump", "jump");
}

jump(str) {
  if (!str) { return; }
  if (str != "from window") {
    write("Jump from what?\n");
    return 1;
  }
  write("You open the window and jump.\n");
  say(this_player()->query_name()+" jumps from the window.\n");
  move_object(this_player(), "/world/city/emerald8");
  this_player()->look();
  write("\n...and land on the street, ouch.\n");
  say(this_player()->query_name()+" jumps from a window in the second "+
"floor and lands on the street.\n");
  this_player()->hit_with_spell(50);
  return 1;
}
