inherit"obj/monster";

reset(arg) {
  :: reset(arg);
  if(arg) { reset(arg); }
  set_name("wizard");
  set_level(30);
  set_ep(3000);
  set_al(10);
  set_gender(1);
  set_al_aggr(200);
  set_alias("pianist");
  set_alt_name("pianoman");
  set_race("human");
  set_short("A pianist wizard");
  set_long("You just think 'stop, stop playing piano'. It is so horrible music, if you even\n"
         + "call it music. The pianist hasen't studied piano playing at all, but wizards\n"
         + "like his music, though, could be an effect of being isolated from outer world\n");
  set_aggressive(0);
  set_spell_chance(65, "exs fla blt");
  set_dead_ob(0);
  set_skill("cast essence", 65);
  set_skill("cast fire", 65);
  set_skill("cast bolt", 65);
  set_skill("attack", 68);
  set_skill("stun", 30);
/*  set_dex(80);
  set_con(180);
  set_str(120);
  set_siz(100);*/

}

