inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";

reset(arg) {
  add_exit("west", "swa1e");
  if(mode) add_exit("south", "swa2f");
  short_desc = "swamp";
  long_desc = "swamp 1 f.\n";
}