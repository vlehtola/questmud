inherit "obj/monster";

reset(arg) {
	  int i;
  ::reset(arg);
  if(arg) { return; }
  i = random(2);
  set_level(30+i*5);
    set_name("clay giant");
set_race("giant");
  set_alias("giant");
  set_short("A large clay giant.");
  set_long("This is a large giant made entierlly out of clay. It doesn't have a\n"+
           "face, just a shapeless lump on it's neck.\n");
  set_al(0);
  set_aggressive(0);

}
