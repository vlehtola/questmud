inherit "room/room";

reset(arg) {
  add_exit("north", "swa5e");
  add_exit("west", "swa6d");
  short_desc = "swamp";
  long_desc = "swamp 6 e.\n";
}

init() {
  ::init();
  add_action("sikret", "move");
}

sikret(str) {
  if(str == "south") {
    say(this_player()->query_name() + " goes south through the bushes.\n");
    write("You go south through the bushes.\n");
    move_object(this_player(),"/wizards/ahma/swamp/rooms/spec1.c");
    this_player()->look();
    return 1;
  }
  return 0;
}
