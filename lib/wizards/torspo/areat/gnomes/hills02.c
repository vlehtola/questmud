inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("south", "/wizards/torspo/areat/gnomes/entrance.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/hills03.c");
  short_desc = "Grassy hills";
  long_desc = "The small path continues to the south and north. Far to the north you\n"+
              "manage to see high, snowy mountains. There are no living things in sight,\n"+
              "only some small holes on the ground which might be the entrances to the\n"+
              "nests of different animals.\n";
  items = allocate(3);
  items[0] = "holes";
  items[1] = "Some small animals have dug these holes into the frozen ground";
}
