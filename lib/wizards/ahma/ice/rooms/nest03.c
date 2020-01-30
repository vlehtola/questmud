inherit "room/room";

reset(arg) {
  add_exit("out", "204");
  short_desc = "A clean and cosy mink's nest";
  long_desc = "A small hole in the ground appears to be a mink's nest. The nest\n" +
              "seems to be especially clean for being some animal's household:\n" +
              "the walls are smooth and almost perfectly concave, the bottom of\n" +
              "the nest is covered with thin layer of snow, but still, it is\n" +
              "very smooth. From the hole, which leads out, is shimmering a weak\n" +
              "light into the nest.\n";

  if(!present("mink")) move_object(clone_object("/wizards/ahma/ice/mob/mink"), this_object());
  present("mink")->specname();
}