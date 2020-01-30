inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+32);
  set_name("fire demon");
  set_alt_name("demon");
  set_alias("greater");
  set_short("Greater fire demon");
  set_long("You are looking straight at horned devil and the huge figure is looking back\n" + 
           "at you somewhat angrily. Small flames and some smoke is released from the\n" + 
           "demons mouth with every breath it takes. When it turns at you and breathes,\n" + 
           "you feel a hot gust of wind sweeping against your face, even when the demon\n" + 
           "is many feet away from you. The huge creature looks very dangerous with its\n" + 
           "muscular arms and big, bloody fists. Sharp horns on the top of its head can\n" + 
          "be used as weapons in battle. The demon waits your action.\n");
  set_max_hp(query_hp() + 400);
  set_hp(query_max_hp());
  set_str(query_str() + 35);
  set_al(-55);
  set_aggressive(0);
  set_resists("fire",100);
  set_skill_chance("kick", 90);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Fire demon cracks its knuckles annoyingly.\n";
    chat_str[1] = "Fire demon fires a set of quick punches in the air.\n";
    chat_str[2] = "Fire demon beats itself on the stomach and growls.\n";
  }
  load_chat(3, chat_str);
}