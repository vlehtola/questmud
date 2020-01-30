inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";
int found = 1, second;

reset(arg) {
  if(mode) add_exit("north", "swa1f");
  short_desc = "swamp";
  long_desc = "swamp 2 f.\n";
  if(second) {
    long_desc = "swamp 2 f seconddone.\n";
  }
}

init() {
  ::init();
  add_action("sikret", "enter");
}

sikret(str) {
  if(second) return;
  if(str != "hole") return 0;
  if(!found) return 0;
  write("You enter in the hole.\n");
  say(this_player()->query_name()+" enters in the hole.\n");
  move_object(this_player(), "/wizards/ahma/swamp/rooms/under01.c");
  return 1;
}

set_seconddone() {
  tell_room(this_object(), "A huge rock suddenly falls from the sky and covers the hole on the ground.\n");
  second = 1;
  reset();
  init();
}
  