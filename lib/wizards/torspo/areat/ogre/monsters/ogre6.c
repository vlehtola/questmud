inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(6)+39);
  set_race("ogre");
  set_alias("berserk");
  set_name("berserk");
  set_alt_name("berserker");
  set_short("Ogre berserker");
  set_long("The totally naked ogre berserk is dancing around the bonfire. Strange figures\n"+
           "have been painted all over him. His long hair has been formed into spikes and\n"+
           "painted in several colors. He looks furious and insane.\n");
  set_al(-12);
  set_gender(1);
  set_skill("stun", 50);
  set_skill("deceived attack", 15);
  set_skill("inner strength", 100);
  set_skill("tumble", 3);
  set_skill("strike", 75);
  set_skill_chance("strike", 10);
  set_str(query_str() + 78);
  set_max_hp(query_hp() + 4600);
  set_hp(query_max_hp());
  set_special(18);

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/axe01.c");
   move_object(weapon, this_object());
   init_command("wield axe");
}


special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Ogre roars in FURY and thrusts you with his axe!\n");
  say("Ogre thrusts "+ob->query_name()+" with his axe!\n", ob);
  ob->hit_with_spell(85, "physical");
}

