inherit "room/room";
int third;

reset(arg) {
  add_exit("north", "swa5f");
  short_desc = "swamp";
  if(!third) { long_desc = "swamp 6 f.\n"; }
  else { long_desc = "swamp 6 f thirddone.\n"; }
}

init() {
  ::init();
  add_action("sikret", "move");
}

sikret(str) {
  if(str == "south") {
    say(this_player()->query_name() + " goes south through the bushes.\n");
    write("You go south through the bushes.\n");
    move_object(this_player(),"/wizards/ahma/swamp/rooms/spec2.c");
    this_player()->look();
    return 1;
  }
  return 0;
}

thirddone() {
  remove_exit("north");
  tell_room(this_object(), "A small hill rises up from the ground in north.\n");
  //change long desc
  third = 1;
  reset();
}