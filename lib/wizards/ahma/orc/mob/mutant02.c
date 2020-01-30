inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+45);
  set_name("creature");
  set_alt_name("mutant");
  set_race("mutant");
  set_short("A huge mutant creature");
  set_long("A big humanoid creature is sitting on the floor. It seems to be living in\n" + 
           "its own world somewhere far away from this one. The mutant's skin is gray\n" + 
           "and it is full of incorrecties like bumps and warts. The creature might have\n" + 
           "once been an Orc, but now the race is hardly recognizeable. The creature is\n" + 
           "humming quietly while sitting on the floor.\n");

  set_max_hp(query_hp() + 4000);
  set_hp(query_max_hp());
  set_str(query_str() + 120);
  set_skill("doublehit", 40);
  set_skill("critical", 50);
  set_skill("find weakness", 30);
  set_skill("enhance criticals", 30);
  set_skill("deceived attack", 40);
  set_skill("kick", 100);
  set_skill_chance("kick", 90);
  set_skill("tumble", 20);
  set_skill("reflect spell", 17);
  set_al(-50);
}
