inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(7)+36);
  set_race("ogre");
  set_alias("monk");
  set_name("monk");
  set_short("Ogre monk");
  set_long("The ogre is clad in black robe and carries a huge ankh in his neck.\n"+
           "You notice the robe is covered with dried blood, maybe caused by ceremonies\n"+
           "of this strange cult.\n");
  set_al(-20);
  set_gender(1);
  set_skill("deceived attack", 15);
  set_skill("tumble", 3);
  set_skill("inner strength", 100);
  set_skill("stun", 40);
  set_str(query_str() + 35);
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_special(15);

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/dagger01.c");
   move_object(weapon, this_object());
   init_command("wield dagger");
}


special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Ogre thrusts his dagger into your flesh.\n");
  say("Ogre thrusts "+ob->query_name()+" with his dagger.\n", ob);
  ob->hit_with_spell(85, "physical");
}

