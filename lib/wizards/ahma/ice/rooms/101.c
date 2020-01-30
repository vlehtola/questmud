inherit "room/room";

reset(arg) {
  add_exit("southwest", "outmap: 140 161");
  add_exit("east", "102");
  short_desc = "An entrance to a icy cavern";
  long_desc = "A cold breeze blows along the snowy walls of this dim cavern. Some small\n" +
              "icicles are attached to the ceiling, pointing down with their lethally\n" +
              "sharp heads. Some light is shimmering into the cavern from west, where\n" +
              "the exit is. The cavern continues to east.\n";
}

init() {
  ::init();
  call_out("icedrop", 1);
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(200)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    this_player()->hit_with_spell(random(31) + 1);
    say("An icicle hits " + this_player()->query_name() + "!\n");
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}
