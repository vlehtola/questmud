inherit "obj/monster";

reset(arg) {
  object weapon;
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(45);
  set_race("ogre");             
  set_name("guardian");
  set_alias("guard");
  set_short("Hairy ogre guardian <patrolling>");
  set_long("Hairy ogre, the guardian of the house, frightens newbie adventures with\n"+
           "his large size, hairy skin and green eyes.\n");
  set_al(-5);
  set_gender(1);
  set_block_dir("enter");
  set_skill("tumble", 5);
  set_skill("deceived attack", 15);
  set_skill("inner strength", 100);
  set_skill("stun", 45);
  set_skill("strike", 85);
  set_skill_chance("strike", 25);
  set_skill("kick", 100);
  set_skill_chance("kick", 30);
  set_str(query_str() + 35);
  set_dex(query_dex() + 15);
  set_max_hp(query_hp() + 5500);
  set_hp(query_max_hp());
  set_special(18);

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/axe01.c");
   move_object(weapon, this_object());
   init_command("wield axe");

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/plate01.c");
   move_object(armour, this_object());
   init_command("wear plate");
}


special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Ogre roars in FURY and thrusts you with his axe!\n");
  say("Ogre thrusts "+ob->query_name()+" with his axe!\n", ob);
  ob->hit_with_spell(85);
}

