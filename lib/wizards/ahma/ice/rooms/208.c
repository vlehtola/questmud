inherit "room/room";

reset(arg) {
  add_exit("south", "205");
  add_exit("enter", "i03");
  add_exit("hole", "nest06");
  short_desc = "An end of a tunnel full of snow";
  long_desc = "The snow-level in this tunnel reaches up to your knees. The cold snow makes\n" +
              "the moving in this part very uncomfortable. By the wall, to where the tunnel\n" +
              "ends, is a carefully built igloo. Igloo's doorway is blocked with a black\n" +
              "cloth. Though the cloth does not prevent anyone from entering the igloo, it\n" +
              "prevents the heat from leaving out of the igloo via the doorway. The snow\n" +
              "has been removed around the doorway. In the eastern side of the igloo is\n" +
              "a place for a campfire, and in the western side there seems to be a hole\n" +
              "in the ground. The ceiling of the tunnel is full of small icicles.\n";
  items = allocate(4);
  items[0] = "hole";
  items[1] = "A small hole is located in the ground by the western wall. It might be\n" +
             "an entrance to some animal's nest";
  items[2] = "campfire";
  items[3] = "A handy place for a campfire has been made near the igloo's entrance. The\n" +
             "campfire is probably used to warm the different meats before eating. The\n" +
             "campfire seems to be burnt out a long time ago";
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(180)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    this_player()->hit_with_spell(random(38) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}