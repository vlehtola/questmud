inherit "obj/monster";
reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) { return; }

 set_level(random(5)+34);
  set_race("ogre");
  set_name("ogre");
  set_short("Young ogre");
  set_long("Ogre looks quite muscular and big. He doesn't seem to be full grown yet though.\n"+
           "He's wearing only some crappy fur rags and is wielding a low quality weapon.\n"+
           "Sure he would hit you hard but not as hard as his older friends.\n");
  set_al(-5);
  set_gender(1);
  set_skill("stun", 30);
  set_skill("tumble", 2);
  set_skill("kick", 100);
  set_skill("inner strength", 100);
  set_skill("deceived attack", 15);
  set_skill_chance("kick", 30);
  set_str(query_str() + 31);
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_special(15);

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
