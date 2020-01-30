inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "A dark tunnel";
  long_desc = "You are standing in a dark tunnel, which is carved into rock.\n"+
	"There is a rotten smell on the air. You feel spooky.\n";
  add_exit("north", "/wizards/celtron/maze/necro/4");
  add_exit("south", "/wizards/celtron/maze/necro/2");
}


