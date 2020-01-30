inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(37+random(5));
  set_race("ogre");
  set_name("fisherman");
  set_short("Ogre fisherman");
  set_long("The bored looking ogre is clad in some sturdy, dirty clothes. He whistles\n"+
           "some happy tune while fixing his fishing net.\n");
  set_al(-1);
  set_gender(1);
  set_skill("inner strength", 100);
  set_skill("deceived attack", 15);
  set_skill("tumble", 4);
  set_skill("stun", 40);
  set_dex(query_dex() + 25);
  set_str(query_str() + 31);
  set_max_hp(query_hp() + 5250);
  set_hp(query_max_hp());
}
