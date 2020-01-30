inherit "obj/monster";
int i = random(3);

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(30 + (i*2));
  set_name("elemental");
  set_alias("minion");
  set_race("elemental");
  if(i==0) { set_short("Hostile-looking earth elemental"); }
  if(i==1) { set_short("Earth elemental minion is protecting its leader"); }
  if(i==2) { set_short("Strong earth elemental is backing Kleod up"); }
  set_long("A hostile earth elemental has been summoned to protect its leader,\n" +
           "Kleod. This elemental looks prepared to do anything for saving its\n" +
           "summoner's life. The elemental looks both sturdy and strong and is\n" +
           "extremely dangerous creature to play with.\n");
  
  set_dead_ob(this_object());  
  set_aggressive(1); 
  set_str(query_str() * 2);
  set_max_hp(query_hp() + 1200);
  set_hp(query_max_hp());

  set_skill("kick", 100);
  set_skill_chance("kick", 90);
  set_skill("bare hands", 100);
  set_skill("punch", 100);
  set_skill("critical", 90);
  set_skill("enhance criticals", 70);
  set_skill("find weakness", 75);
  set_resists("electric", 100);
  set_al(-30);
}

monster_died() {
  if(present("kleod", environment(this_object()))) {
    present("kleod", environment(this_object()))->reducecloned();
  }
  return 0;
}
