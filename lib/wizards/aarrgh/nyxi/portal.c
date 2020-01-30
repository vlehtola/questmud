inherit "room/room";

reset(arg) {
set_light(1);
set_not_out(1);
            add_exit("out", "/wizards/aarrgh/nyxi/volcano8");
            add_exit("north", "/wizards/aarrgh/nyxi/cave");
            short_desc = "In another dimension";
long_desc = "This is the portal room between two dimensions. It now lies behind. Thick\n"
            "darkness surrounds the area. It's difficult to see but path leading north\n"
            "can be noticed.\n"
            "The portal is the only exit to normal dimension.\n";

items = allocate(4);
  items[0] = "darkness";
  items[1] = "You can almost touch the darkness";


}
