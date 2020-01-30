inherit "room/room";

reset(arg) {
  add_exit("north", "206");
  add_exit("hole", "nest05");
  short_desc = "An end of a spacious tunnel";
  long_desc = "A spacious tunnel ends into a steep, vertical wall. The snow has melted\n" +
              "from the ceiling in this part of the cavern, which seems a bit strange\n" +
              "to you. Despite the ceiling's abnormality, the walls are covered in thick\n" +
              "layer of snow, alike everywhere else in the caverns. A small hole can be\n" +
              "seen on the ground, just by the southern wall. In north, where the tunnel\n" +
              "ends, can be seen some kind of an opening. Some lethal-looking icicles\n" +
              "hang from the ceiling.\n";
  items = allocate(2);
  items[0] = "hole";
  items[1] = "A small hole is located in the ground by the southern wall. It might be\n" +
             "an entrance to some animal's nest";
  if(!present("husky")) move_object(clone_object("/wizards/ahma/ice/mob/husky"), this_object());
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(180)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Husky") return;
    this_player()->hit_with_spell(random(38) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}