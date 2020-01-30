 inherit "obj/monster";

reset(arg) {
  object weapon;
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(45);
  set_race("ogre");             
  set_name("guard");
  set_short("King's elite guard");
  set_long("This well-trained ogre is elite guard of the king itself. He has spent\n"+
           "all his life just serving his lord and now, at last, has managed to get this\n"+
           "position. He watches your every move very carefully.\n");
  set_al(-10);
  set_gender(1);
  set_special(100);
  set_skill("strike", 100);
  set_skill("deceived attack", 15);
  set_skill_chance("strike", 25);
  set_str(query_str() + 50);
  set_max_hp(query_hp() + 5500);
  set_hp(query_max_hp());

   weapon = clone_object("/wizards/torspo/areat/ogre/monsters/eq/axe01.c");
   move_object(weapon, this_object());
   init_command("wield axe");

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/plate01.c");
   move_object(armour, this_object());
   init_command("wear plate");
}

special_move() {
 object ob;
 ob = present("king", environment(this_object()));
 if(attacker_ob && ob) {
   tell_room(environment(this_object()), "King doesn't seem to like your actions.\n");
   ob->attack_object(attacker_ob);
 }
}
