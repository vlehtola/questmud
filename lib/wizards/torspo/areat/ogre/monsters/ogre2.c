inherit "obj/monster";

reset(arg) {
  object weapon;
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5)+39);
  set_race("ogre");
  set_name("ogre");
  set_alias("warrior");
  set_short("Ogre warrior");
  set_long("The muscular ogre looks quite experienced in fighting. He has some scars\n"+
           "in his face and the way he wields his weapon shows that this one won't be\n"+
           "so easy enemy to fight against.\n");
  set_al(-5);
  set_gender(1);
  set_skill("tumble", 3);
  set_skill("inner strength", 100);
  set_skill("stun", 35);
  set_skill("kick", 100);
  set_skill_chance("kick", 50);
  set_skill("deceived attack", 15);
  set_skill("strike", 60);
  set_skill_chance("strike", 5);
  set_str(query_str() + 32);
  set_max_hp(query_hp() + 5200);
  set_hp(query_max_hp());
  set_special(16);

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/mace02.c");
   move_object(weapon, this_object());
   init_command("wield mace");

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/leather01.c");
   move_object(armour, this_object());
  init_command("wear armour");
}


special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Ogre roars in FURY and beats you with his mace!\n");
  say("Ogre beats "+ob->query_name()+" with his mace!\n", ob);
  ob->hit_with_spell(85, "physical");
}

