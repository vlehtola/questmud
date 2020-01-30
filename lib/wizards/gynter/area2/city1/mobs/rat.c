inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(10);
  set_name("rat");
  set_short("A disgusting rat");
  set_long("A small disgusting rat. It is thin, grey and ugly. Not that\n"+
           "anyone can say that a rat has ever been beautiful.\n");
  set_al(-40);
  set_aggressive(0);
  set_animal(1);
}
