inherit "room/room";

reset(arg) {
  add_exit("out", "112");
  short_desc = "An igloo made of frozen snow";
  long_desc = "From inside the igloo feels amazingly warm. There must be at least couple,\n" +
              "or even more, degrees higher temperature than outside. A tiny hole has been\n" +
              "made in the ceiling to prevent the carbon dioxide from accumulating inside\n" +
              "the igloo, thus raising the temperature and melting the snow. The igloo\n" +
              "looks very plain from inside. Two warm hides are lying by the southern wall.\n" +
              "A small wooden table and chair are located by the eastern wall.\n";
  items = allocate(10);
  items[0] = "hide";
  items[1] = "Try looking at 'hides'";
  items[2] = "hides";
  items[3] = "Two hides of some unknown animal have been laid by the southern wall. The\n" +
             "hides are used to warm up with the campfire just before sleeping. Sleeping\n" +
             "with inadequate warmth around humanoid is a lethal action";
  items[4] = "table";
  items[5] = "A simple wooden table is standing by the eastern wall. A white plate, with\n" +
             "some remains of food on it, is placed on the table. A wooden chair is\n" +
             "standing next to the table";
  items[6] = "plate";
  items[7] = "A simple white plate. Some remains of food, probably some meat, has been\n" +
             "left on the plate. Nothing out of ordinary can be seen about it";
  items[8] = "chair";
  items[9] = "A simple wooden chair is standing next to the table. Nothing out of ordinary\n" +
             "can be seen about it";
  if(!present("terran")) {
    move_object(clone_object("/wizards/ahma/ice/mob/dwarf01"), this_object());
  }
}

init() {
  ::init();
  add_action("hep", "take");
  add_action("hep", "get");
}

hep(str) {
  if(str == "plate") { write("You don't need to take the simple plate.\n"); return 1; }
  if(str == "chair") { write("You don't need to take the simple wooden chair.\n"); return 1; }
  if(str == "table") { write("You don't need to take the simple wooden table.\n"); return 1; }
  return;
}
