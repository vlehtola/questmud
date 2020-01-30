inherit "room/room";

reset(arg) {
  add_exit("west", "104");
  add_exit("southeast", "110");
  short_desc = "A small snowy tunnel";
  long_desc = "Tunnel walls rise up from the ground frozen. Some animal voices echo in\n" +
              "the narrow passages. The ceiling, which is at least eight feet high, is\n" +
              "full of sharp, frozen icicles. Some water can be seen running on the\n" +
              "frozen northern wall. It must flood in from somewhere near the ceiling.\n" +
              "The tunnel floor is covered in thin snow, which makes the moving at the\n" +
              "same time more comfortable and harder. The tunnel continues to west and\n" +
              "southeast.\n";
  items = allocate(4);
  items[0] = "water";
  items[1] = "Some water is flowing down on the northern wall. There must be a small hole\n" +
             "somewhere near the assembling-point of the wall and the ceiling. The water\n" +
             "seems to froze quite rapidly after it has flooded into these chilly caverns";
  items[2] = "snow";
  items[3] = "A layer of thin snow is covering the tunnel bed. The snow makes a soft\n" +
             "snaring sound when stepping on it. Your feet somewhat sink into the snow\n" +
             "due to the weight they are holding on them";
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