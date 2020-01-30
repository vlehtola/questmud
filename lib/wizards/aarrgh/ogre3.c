inherit "obj/monster";

reset(arg) {
  object weapon;
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+43);
  set_name("soldier");
  set_race("ogre");
  set_short("Ogre soldier");
  set_long("The full trained ogre is ready for a war. He's veteran of many duels\n"+
           "and knows the dirty tricks and ways to kill ones opponent.\n");
  set_al(-8);
  set_gender(1);
  set_skill("tumble", 3);
  set_skill("deceived attack", 15);
  set_skill("inner strength", 100);
  set_skill("stun", 45);
  set_skill("kick", 100);
  set_skill_chance("kick", 40);
  set_skill("strike", 70);
  set_skill_chance("strike", 10);
  set_str(query_str() + 33);
  set_max_hp(query_hp() + 5400);
  set_hp(query_max_hp());
  set_special(17);

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/plate01.c");
   move_object(armour, this_object());
   init_command("wear plate");

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/mace01.c");
   move_object(weapon, this_object());
   init_command("wield mace");
}


special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Ogre roars in FURY and beats you with his mace!\n");
  say("Ogre beats "+ob->query_name()+" with his mace!\n", ob);
  ob->hit_with_spell(85);
}

