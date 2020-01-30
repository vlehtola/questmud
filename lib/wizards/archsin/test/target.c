inherit "obj/monster";

int follow;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(1);
  set_name("target");
  set_alias("dummy");
  set_short("Targeting dummy");
  set_long("Targeting dummy.\n");
  set_aggressive(0);
  set_random_pick(0);
  set_regen(query_max_hp()/20);
  set_al_aggr(0);
  set_al(0);
  set_max_hp(query_max_hp()*40000);
  set_gender(1);
  set_str(1);
}
