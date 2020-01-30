inherit "room/room";

reset(arg) {
  add_exit("northeast", "302");
  add_exit("ladders", "212");
  short_desc = "An end of a snowy and narrow tunnel";
  long_desc = "An extremely narrow tunnel leads northeast from here. To be able to fit\n" +
              "in the tunnel, you are forced to crawl onwards. Somewhat large amount of\n" +
              "very soft snow covers the bottom of this tunnel, reaching almost up to\n" +
              "your thighs when crawling. Tunnel's walls look like they would be filled\n" +
              "with sharp knives as the dim light reflects from the sharp edges of ice\n" +
              "from the walls. Frozen ladders lead upwards by the southern end of the\n" +
              "tunnel.\n";
}

init() {
  ::init();
  add_action("northeast", "northeast");
  if(this_player()->query_name() == "Dooris") call_out("dooris", 1);
}

northeast() {
  write("You start crawling in the narrow tunnel.\n");
  call_out("moveon", (random(3) + 1), 0);
  return 1;
}

moveon(i) {
  if(i == 0) this_player()->move_player("northeast#/wizards/ahma/ice/rooms/302.c");
  return 1;
}

dooris() {
  say("Dooris says: 'This is not where I wanted to go. Come get me from my igloo\n" +
      "              when you have cleared your head.'\n");
  move_object(present("dooris"), "/wizards/ahma/ice/rooms/i05");
  tell_room("/wizards/ahma/ice/rooms/i05", "Dooris arrives from out.\n");
  return 1;
}