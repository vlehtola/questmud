inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";

reset(arg) {
  if(!mode) add_exit("south", "swa3c");
  else remove_exit("south");  
  add_exit("west", "swa2b");
  short_desc = "swamp";
  long_desc = "swamp 2 c.\n";
}