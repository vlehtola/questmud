inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";

reset(arg) {
  add_exit("west", "swa1c");
  if(mode) add_exit("south", "swa2d");
  short_desc = "swamp";
  long_desc = "swamp 1 d.\n";
}