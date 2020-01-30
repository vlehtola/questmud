inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "An underground graveyard";
  long_desc = "You are in an underground graveyard, which is carved into rock.\n"+
	"There is a rotten smell on the air. You have a REALLY bad feeling about this place.\n"+
	"You can hear something unusual voices from the north.\n";
  add_exit("north", "/wizards/celtron/maze/necro/7");
  add_exit("south", "/wizards/celtron/maze/necro/5");
}


