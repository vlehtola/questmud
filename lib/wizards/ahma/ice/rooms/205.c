inherit "room/room";

reset(arg) {
  add_exit("north", "208");
  add_exit("south", "206");
  add_exit("west", "209");
  add_exit("east", "202");
  add_exit("southeast", "203");
  short_desc = "A large opening full of icicles";
  long_desc = "You are standing in a huge opening. The ceiling is at least in the height\n" +
              "of thirteen feet. The ground is almost fully frozen, though some piles of\n" +
              "soft snow can be seen here and there. The opening continues to east- and\n" +
              "southwards. Two snowy tunnels lead to north and west. The ceiling of the\n" +
              "cavern is full of sharp icicles.\n";
  if(!present("baby")) move_object(clone_object("/wizards/ahma/ice/mob/byeti"), this_object());
}

init() {
  ::init();
  call_out("icedrop", 1);
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(180)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Baby yeti") return;
    this_player()->hit_with_spell(random(38) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}
