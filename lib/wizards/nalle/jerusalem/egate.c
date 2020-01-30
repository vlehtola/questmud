inherit "room/room";

reset(arg) {
add_exit("west","wizards/nalle/jerusalem/vd9");
add_exit("east","out: 90 105");
  short_desc = "St. Stevens gate";
  long_desc =
"This is the eastern gate of the city of Jerusalem,\n" +
"called St. Stevens gate. The biggest road of the city,\n" +
"is located to your west, but does not seem extremely\n" +
"crowded right there, where you stand. However, you\n" +
"notice much more people on the road further east. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/map");
   return 1;
}
