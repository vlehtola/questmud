inherit "room/room";

reset(arg) {
  add_exit("south", "203");
  add_exit("west", "205");
  add_exit("northeast", "201");
  add_exit("southwest", "206");
  add_exit("hole", "nest02");
  short_desc = "A large opening full of icicles";
  long_desc = "You are standing in a huge opening. The ceiling is at least in the height\n" +
              "of thirteen feet. The ground is almost fully frozen, though some piles of\n" +
              "soft snow can be seen here and there. A small hole can be seen in the\n" +
              "ground by the eastern wall. The opening continues to west- and southwards.\n" +
              "The ceiling of the cavern is full of sharp icicles. A smaller tunnel is\n" +
              "leading to northeast, from where you entered this floor\n";
  items = allocate(2);
  items[0] = "hole";
  items[1] = "A small hole is located in the ground by the eastern wall. It might be\n" +
             "an entrance to some animal's nest";
  if(!present("mink")) move_object(clone_object("/wizards/ahma/ice/mob/mink"), this_object());
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
    if(this_player()->query_name() == "Mink") return;
    this_player()->hit_with_spell(random(38) + 1);
    
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}