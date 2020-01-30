inherit "room/room";

reset(arg) {
  add_exit("south", "211");
  add_exit("east", "209");
  add_exit("hole", "nest07");
  short_desc = "A corner of a snowy tunnel";
  long_desc = "The snowy tunnel does a right-angle turn in this part of it. The ceiling\n" +
              "is about eight and a third feet high. The ground is covered in thin\n" +
              "layer of soft snow, but the walls are bald. The ice, which covers the\n" +
              "walls, seems to emit or reflect the light into the tunnel. The tunnel\n" +
              "seems to end in a small distance to south. In east the ground and the\n" +
              "ceiling are pitching upwards. In the ground, by the western wall, there\n" +
              "seems to be a small hole.\n";
  items = allocate(2);
  items[0] = "hole";
  items[1] = "A small hole is located in the ground by the western wall. It might be\n" +
             "an entrance to some animal's nest";
}