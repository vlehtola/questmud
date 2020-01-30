inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(6)+35);
  set_race("ogre");
  set_name("servant");
  set_short("Ogre servant");
  set_long("Quite slender ogre. He's dressed in silk clothes and carries a plate full of\n"+
           "food in his hand.\n");
  set_dex(query_dex() + 35);
  set_str(query_str() + 25);
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_skill("inner strength", 100);
  set_skill("deceived attack", 15);
  set_skill("kick", 100);
  set_skill_chance("kick", 50);
  set_skill("tumble", 4);
  set_skill("stun", 35);
}
