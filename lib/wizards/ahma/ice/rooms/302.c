inherit "room/room";

reset(arg) {
  add_exit("north", "303");
  add_exit("southwest", "301");
  short_desc = "A snowy and narrow tunnel";
  long_desc = "An extremely narrow tunnel leads north and southeast from here. To be able\n" +
              "to fit in the tunnels, you are forced to crawl onwards. Somewhat large\n" +
              "amount of very soft snow covers the bottom of this tunnel, reaching almost\n" +
              "up to your thighs when crawling. Tunnel's walls look like they would be\n" +
              "filled with sharp knives as the dim light reflects from the sharp edges of\n" +
              "ice from the walls. The narrow tunnel seems to continue in southwest and\n" +
              "turning into an opening in north.\n";
  if(!present("adult")) move_object(clone_object("/wizards/ahma/ice/mob/ayeti"), this_object());
  present("adult")->specname();
}

init() {
  ::init();
  add_action("north", "north");
  add_action("southwest", "southwest");
}

north() {
  write("You start crawling in the narrow tunnel.\n");
  call_out("moveon", (random(3) + 1), 0);
  return 1;
}

southwest() {
  write("You start crawling in the narrow tunnel.\n");
  call_out("moveon", (random(3) + 1), 1);
  return 1;
}

moveon(i) {
  if(i == 0) this_player()->move_player("north#/wizards/ahma/ice/rooms/303.c");
  if(i == 1) this_player()->move_player("north#/wizards/ahma/ice/rooms/301.c");
  return 1;
}