inherit "room/room";

inherit "/wizards/ahma/swamp/rooms/swafun";

//int mode;

reset(arg) 
{
  add_exit("south", "swa4a");
  if(mode) add_exit("north", "swa2a");
  short_desc = "swamp";
  long_desc = "swamp 3 a.\n";
}

test() { return mode; }

/*mode2() {
  mode++;
  reset();
}*/
