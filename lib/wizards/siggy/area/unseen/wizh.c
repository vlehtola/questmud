inherit"obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { reset(arg); }
  set_name("wizard");
  set_level(20);
  set_ep(5000);
  set_gender(1);
  set_al(10); 
  set_al_aggr(200);
  set_alias("hiding");
  set_alt_name("wizard");
  set_race("human");
  set_short("Wizard is hiding here");
  set_long("He must be scared of something. He's trying to hide in here. You can\n"
         + "only guess what's gone to him. He's sweating like a pig. He's almost naked.\n");
  set_aggressive(0);
  set_dead_ob(0);
  set_skill("attack", 60);
}
