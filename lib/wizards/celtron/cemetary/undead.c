inherit "/obj/monster";

reset(arg) {
  int i;
  string str;
  ::reset(arg);
  if(arg) return;
  i = random(4);
  set_level(10+i*5);
  set_name("undead");
  set_alias("dead");
  set_undead(1);
  set_aggressive(1);
  str = "small";
  if(i == 1) str = "disgusting";
  if(i == 2) str = "horrible";
  if(i == 3) str = "terrible";
  set_short("A "+str+" living dead");
  set_long("The undead smells bad and seems to be quite aggressive.\n"+
	   "It's clothes are rotting as is it's flesh. Some rib bones\n"+
	   "stick out of what used to be it's stomach and chest.\n");
}
