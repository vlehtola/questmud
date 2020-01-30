inherit "room/room";

reset(arg) {
  add_exit("out", "206");
  short_desc = "A wolverine's nest";
  long_desc = "The tight hole turns out to be a nest of a wolverine. The walls and the\n" +
              "ceiling are covered in frozen snow and on the ground there seems to be\n" +
              "more softer snow. The snow on the ground is mostly coloured in red from\n" +
              "blood, probably from animals that the habitant of this hole has been\n" +
              "hunting for food. A bloody, half-eaten corpse can be seen lying on the\n" +
              "snow.\n";
  items = allocate(2);
  items[0] = "corpse";
  items[1] = "A bloody and half-eaten corpse of a small mink. Some entrails can be\n" +
             "seen near the corpse. Wolverines do not seem to possess any kind of\n" +
             "table manners";

  if(!present("wolverine")) move_object(clone_object("/wizards/ahma/ice/mob/wolverine"), this_object());
}