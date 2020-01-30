inherit "room/room";

reset(arg) {
set_light(1);
set_not_out(1);
            add_exit("northeast", "/wizards/aarrgh/nyxi/gates");
            add_exit("south", "/wizards/aarrgh/nyxi/path3");
            short_desc = "in the path to the volcano";
long_desc = "A small path leads to volcano. Eternal night darkens the sky. A shed skin lie\n"
            "on the ground. Some terrible howling can be heard near. This place can make even\n"
            "the bravest of warriors shiver with fear.\n";

  items = allocate(4);
  items[0] = "skin";
  items[1] = "Some shed snake skin";



}