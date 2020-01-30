inherit "room/room";
inherit "/wizards/ahma/swamp/rooms/swafun";

reset(arg) {
  if(!mode) {
    add_exit("north", "swa2c");
    add_exit("south", "swa4c");
  }
  else {
    if(mode == 1) {
      remove_exit("north");
      remove_exit("south");
    }
    else {
    add_exit("west", "swa3b");
    add_exit("east", "swa3d");
    }
  }
  short_desc = "swamp";
  long_desc = "swamp 3 c.\n";
}