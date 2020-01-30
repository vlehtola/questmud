inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";
int found = 1;

reset(arg) {
  add_exit("north", "swa3d");
  add_exit("south", "swa5d");
  add_exit("west", "swa4c");
  if(mode) remove_exit("north");
  short_desc = "swamp";
  long_desc = "swamp 4 d.\n";
}

init() {
  ::init();
  add_action("sikret", "enter");
}


//tullaan undergroundista tänne ni sit on foundi.
sikret(str) {
  if(str != "tree") return 0;
  if(!found) return 0;
  if(mode < 1) return 0;
  write("You enter in the tree.\n");
  say(this_player()->query_name()+" enters in the tree.\n");
  move_object(this_player(),"/wizards/ahma/swamp/rooms/tree.c");
  this_player()->look();
  return 1;
}

remexit() {
  remove_exit("west");
  tell_room(this_object(), "exitti meni\n");
}

addexit() {
  add_exit("west", "swa4c");
  tell_room(this_object(), "exitti tuli\n");
}