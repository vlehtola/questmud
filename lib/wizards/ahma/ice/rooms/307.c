inherit "room/room";

reset(arg) {
  add_exit("north", "310");
  add_exit("west", "306");
  add_exit("northwest", "309");
  short_desc = "On a frozen pond";
  long_desc = read_file("/wizards/ahma/ice/rooms/icedesc");
}

init() {
  ::init();
  call_out("icedrop", 1);
  add_action("north", "north");
  add_action("west", "west");
  add_action("northwest", "northwest");
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(100)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    this_player()->hit_with_spell(random(51) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}

north() {
  write("You start slippering onwards on the icy surface.\n");
  call_out("moveon", (random(3) + 1), 0);
  return 1;
}

west() {
  write("You start slippering onwards on the icy surface.\n");
  call_out("moveon", (random(3) + 1), 1);
  return 1;
}

northwest() {
  write("You start slippering onwards on the icy surface.\n");
  call_out("moveon", (random(3) + 1), 2);
  return 1;
}

moveon(i) {
  if(i == 0) this_player()->move_player("north#/wizards/ahma/ice/rooms/310.c");
  if(i == 1) this_player()->move_player("west#/wizards/ahma/ice/rooms/306.c");
  if(i == 2) this_player()->move_player("northwest#/wizards/ahma/ice/rooms/309.c");
  return 1;
}