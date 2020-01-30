inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(6)+32);
  set_race("ogre");
  set_alias("noble");
  set_name("ogre");
  set_short("Ogre noble");
  set_long("This ogre looks a lot thinner and weaker than the warriors you encountered\n"+
           "before. He's clad in fine and clean clothes and it seems he has cut his hair\n"+
           "recently.\n");
  set_al(-1);
  set_gender(1);
  set_skill("stun", 35);
  set_skill("deceived attack", 15);
  set_skill("tumble", 3);
  set_skill("inner strength", 100);
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_str(query_str() + 30);
}
