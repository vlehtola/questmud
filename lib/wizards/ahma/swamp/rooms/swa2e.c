inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";

reset(arg) {
  add_exit("north", "swa1e");
  add_exit("west", "swa2d");
  if(mode) add_exit("south", "swa3e");
  short_desc = "swamp";
  long_desc = "swamp 2 e.\n";
}