inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2) + 35);
  set_name("hitman");
  set_alias("man");
  set_gender(1);
  set_race("orc");
  set_short("A muscular Orcish hitman");
  set_long("A muscular hitman has been summoned here to kill everyone who opposes\n" + 
           "Chief Tas'gand. The hitman is wearing a hood which prevents others from\n" + 
           "seeing his face. Though a furious stare from glittering eyes penetrates\n" + 
           "the darkness inside the hood and lands on you. A hitmen are supposed to\n" + 
           "be feared and skillful fighters with lots of pure strength in their bare\n" +
           "arms and fists.\n");

  set_max_hp(query_hp() + 3072);
  set_hp(query_max_hp());
  set_str((query_str() * 2) + 50);
  set_dex(query_dex() * 2);
  set_aggressive(1);

  if(!present("hood", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/blackhood"), this_object()); init_command("wear hood"); }
  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/blackrobes"), this_object()); init_command("wear robes"); }

  set_skill("dodge", 30);
  set_skill("tumble", 30);
  set_skill("foresee attack", 30);
  set_skill("alertness", 50);
  set_skill("doublehit", 45);
  set_skill("critical", 70);
  set_skill("enhance criticals", 45);
  set_skill("find weakness", 55);
  set_skill("kick", 100);
  set_skill_chance("kick", 90);
  set_al(-60);
}