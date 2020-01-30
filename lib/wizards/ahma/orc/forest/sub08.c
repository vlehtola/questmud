inherit "room/room";
int h = random(3);

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/sub10");
  add_exit("south", "/wizards/ahma/orc/forest/sub05");
  add_exit("west", "/wizards/ahma/orc/forest/sub09");
  add_exit("east", "/wizards/ahma/orc/forest/sub07");
  short_desc = "In an underground opening";
  long_desc = read_file("/wizards/ahma/orc/forest/subdesc") + "\n";
}