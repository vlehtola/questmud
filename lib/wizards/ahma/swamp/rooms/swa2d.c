inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";

reset(arg) {
  if(!mode) add_exit("south", "swa3d");
  else { remove_exit("south"); add_exit("north", "swa1d"); }
  add_exit("east", "swa2e");
  short_desc = "swamp";
  long_desc = "swamp 2 d.\n";
}