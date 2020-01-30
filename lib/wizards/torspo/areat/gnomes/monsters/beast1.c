inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(12 + random(2));
  set_name("wolf");
  set_alias("beast");
  set_race("wolf");
  set_animal(1);
  set_short("Gray wolf");
  set_long("Hairy gray wolf stands here guarding its home cave. Due to lack of food and\n"+
           "hard living it is quite small and weak. Still you should fear its sharp fangs\n"+
           "and teeth.\n");
  set_al(-1);
  set_al_aggr(200);
}
