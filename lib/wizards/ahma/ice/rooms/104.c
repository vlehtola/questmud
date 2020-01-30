inherit "room/room";

reset(arg) {
  add_exit("east", "105");
  add_exit("southwest", "102");
  short_desc = "A small snowy tunnel";
  long_desc = "Soft breeze of cold air floats through this part of the tunnel system.\n" +
              "The freezing air seems to be flooding into the room through a tiny hole\n" +
              "near the ceiling. Some light is also luminating into the room through the\n" +
              "hole. The ceiling of the tunnel is concave-shaped, and from the center, it\n" +
              "reaches in the height of eight feet. Some icicles are hanging from the\n" +
              "ceiling. All around the tunnel floor can be seen lying lots of thin snow.\n" +
              "The small tunnel continues to east. In southwest can be seen a small opening.\n";
  items = allocate(4);
  items[0] = "hole";
  items[1] = "A small hole near the ceiling of the tunnel seems to penetrate the mountain\n" +
             "all the way to the surface. From the hole is shimmering a weak light and\n" +
             "some breezes of cold air flood into this part of the tunnel through it";
  items[2] = "snow";
  items[3] = "The snow in this part of the tunnel seems to be very fine and thin. The soft\n" +
             "snow feels comfortable under your feet and no footprints can be recognized\n" +
             "from the fine mass of snow even when examining more carefully";
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