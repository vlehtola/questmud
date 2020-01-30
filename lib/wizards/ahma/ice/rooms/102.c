inherit "room/room";

reset(arg) {
  add_exit("west", "101");
  add_exit("east", "103");
  add_exit("northeast", "104");
  add_exit("southeast", "106");
  short_desc = "An intersection between tunnels";
  long_desc = "The cavern separates in four directions from this small opening. Though\n" +
              "light sources cannot be seen in the opening, the snowy walls seem to\n" +
              "reflect the light so much, that it seems like the walls would be emitting\n" +
              "a faint white light by themselves. Some small icicles are hanging from the\n" +
              "ceiling. Three smaller tunnels continue to eastwards and a bigger corridor\n" +
              "is leading to the west.\n";
  if(!present("husky")) move_object(clone_object("/wizards/ahma/ice/mob/husky"), this_object());
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
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Husky") return;
    this_player()->hit_with_spell(random(31) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}