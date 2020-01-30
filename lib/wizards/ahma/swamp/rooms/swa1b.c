inherit "room/room";

reset(arg) {
  add_exit("south", "swa2b");
  add_exit("east", "swa1c");
  short_desc = "swamp";
  long_desc = "swamp 1 b.\n";
}

init() {
  ::init();
  add_action("sikret", "move");
}

sikret(str) {
  if(str == "north") {
    say(this_player()->query_name() + " goes north through the bushes.\n");
    write("You go north through the bushes.\n");
    move_object(this_player(),"/wizards/ahma/swamp/rooms/spec3.c");
    this_player()->look();
    return 1;
  }
  return 0;
}
