inherit "room/room";

reset(arg) {

  short_desc = "Calm down";
  long_desc = "Just calm down a bit, will you?\n";
  
  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
}


init() {
  ::init();
  add_action("yeah", "ld");
  add_action("yeah", "quit");
  add_action("yeah", "tell");
  add_action("yeah", "shout");
  add_action("yeah", "fin");
  add_action("yeah", "mud");
  add_action("yeah", "newbie");
  add_action("yeah", "wanted");
  add_action("yeah", "sales");
  add_action("yeah", "kill");
  add_action("yeah", "use");
  add_action("yeah", "cast");
}


yeah() {
	write("Calm down!\n");
	return 1;
}