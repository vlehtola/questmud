
inherit"obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { reset(arg); }
  set_name("drunkard");
  set_level(26);
  set_ep(2000);
  set_gender(1);
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_alt_name("drunk");
  set_race("human");
  set_short("Wizard drinking beer");
  set_long("Wizards really do drink alcohol. The wizard is having fun and singing. Wizard's\n"
         + "robe is very battered and ugly. Wizard has a beer bottle in his hand.\n"
         + "He smells alcohol badly\n");
  set_aggressive(0);
  set_spell_chance(60, "exs fla grs");
  set_dead_ob(0);
  set_skill("attack", 53);
  set_skill("doublehit", 50);
  set_skill("stun", 10);
  set_skill("cast essence", 60);
  set_skill("cast fire", 60);
  set_skill("cast grasp", 60);
  set_skill("mana control", 35);
  set_skill("chanting", 50);
/*  set_dex(120); 
  set_con(200);
  set_str(135);
  set_siz(100);
*/
}
