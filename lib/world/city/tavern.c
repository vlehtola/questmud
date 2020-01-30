inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("west", "/world/city/inn");
  short_desc = "Tavern";
  long_desc = 	"The tavern is full of people discussing, laughing, drinking and exchanging\n"+
		"stories. Thin smoke covers the ceiling and the air contains various odors.\n"+
		"Wooden furniture calls tired adventurers to sit back and relax.\n";

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  set_not_out(1);
  set_light(3);

}







