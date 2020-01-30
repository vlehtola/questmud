inherit "room/room";

reset(arg) {
  add_exit("west", "303");
  add_exit("cave", "nest01");
  short_desc = "A promontory reaching over a frozen pond";
  long_desc = "The snowy path ends into a promontory which seems to be about fifteen feet\n" +
              "above an icy pond. In north opens a huge opening lined by high frozen walls.\n" +
              "The most of the opening is covered with sparkling, freezy-looking ice, but\n" +
              "far beyond the icy area in north can be seen some small dwellings, like\n" +
              "igloos. Some icicles can be seen hanging from the ceiling of this dead end.\n" +
              "A cave entrance is gaping in the southern wall. A small path leads back to\n" +
              "the west.\n";

  if(!present("baby 2")) move_object(clone_object("/wizards/ahma/ice/mob/bbear"), this_object());
  if(!present("baby 2")) move_object(clone_object("/wizards/ahma/ice/mob/bbear"), this_object());
  if(!present("adult")) move_object(clone_object("/wizards/ahma/ice/mob/abear"), this_object());
}

init() {
  ::init();
  call_out("icedrop", 1);
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(120)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Bear") return;
    this_player()->hit_with_spell(random(47) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}