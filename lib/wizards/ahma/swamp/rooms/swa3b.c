inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";

reset(arg) {
  if(mode == 2) {
  add_exit("east", "swa3c");
  add_exit("portal", "path01");
  }
  short_desc = "swamp";
  long_desc = "swamp 3 b.\n";
}