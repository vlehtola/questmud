inherit "room/room";

reset(arg) {
  add_exit("north", "110");
  add_exit("west", "107");
  short_desc = "A corner of narrow tunnel";
  long_desc = "The narrow, uncomfortable tunnel makes a right-angle turn here. The icy\n" +
              "wall which can be seen in front of you seems to be shimmering softly in\n" +
              "the weak light. A part of the tunnel floor near the turn seems to have\n" +
              "collapsed. Through the hole can be seen into a lower level of the\n" +
              "tunnel system. The narrow tunnel leads to west and north.\n";
   items = allocate(2);
   items[0] = "hole";
   items[1] = "A small hole has formed on the ground because of a minor collapse in this\n" +
              "part of the tunnel. Hole's diameter seems to be about six inches. Through\n" +
              "the hole can be seen into a second lever of the tunnel system. Nothing out\n" +
              "of ordinary can be seen through the hole at the moment";
}

init() {
  ::init();
  add_action("hep", "dig");
  add_action("hap", "enter");
}

hep(str) {
  if(str != "hole") return;
  write("The ground around the hole seems to be very sturdy and you cannot dig the\n" +
        "hole bigger. Not even with an appropriate equipment.\n");
  say(this_player()->query_name() + " tries to make the hole on the ground bigger by digging it, but the\n" +
      "ground around the hole seems to be too sturdy for digging.\n");
  return 1;
}

hap(str) {
  if(str != "hole") return;
  write("You are way too big to fit into the hole with a diameter of six inches.\n");
  return 1;
}
