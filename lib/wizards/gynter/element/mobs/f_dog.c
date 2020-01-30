inherit "obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) { return; }
set_race("dog");
  i = random(2);
  set_level(10+i*5);
  set_name("dog");
  set_alias("dog");
  set_short("A fire dog");
  set_long("These are the pets of the fire demons.\n" +
  "They look exactly like a normal dog, except that they are burning!\n");
  set_al(70);
  set_aggressive(0);

}
