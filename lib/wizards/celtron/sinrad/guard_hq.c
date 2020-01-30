inherit "room/room";

reset(arg) {
  if(!present("sinrad")) {
	move_object(clone_object("/wizards/celtron/sinrad/sinrad"),
	this_object());
  }
  if(!present("guard")) {
	move_object(clone_object("/world/monsters/guard"), this_object());
  }
  if(arg) return;
  add_exit("east", "world/city/emerald2");
  short_desc = "Cityguards headquarters";
  long_desc = "There are weapons and armour hanging from the walls.\n"+
	"The whole place is a dim cave digged in rockmade building.\n";
}


