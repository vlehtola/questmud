
inherit"obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_name("drunk");
  set_level(48);
  set_ep(5000);
  set_al(10); 
  set_al_aggr(200);
  set_alias("drunkard");
  set_race("human");
  set_short("Drunken wizard");
  set_long("Yeah, wizards do drink alcohol, a lot too.\n");
  set_wc(28);
  set_ac(31); 
  set_aggressive(0);
  set_spell_chance(30, "exs fla blt");
  set_dead_ob(0);
  set_skill("cast essence", 90);
  set_skill("cast fire", 90);
  set_skill("cast bolt", 90);
  set_skill("attack", 100);
  set_skill("stun", 40);
  set_skill("find weakness", 45);

}
