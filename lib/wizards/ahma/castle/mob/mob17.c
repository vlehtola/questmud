inherit "obj/monster";

reset(arg) {
  object club, necklace, plate;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+45);
  set_name("guard");
  set_alias("demon");
  set_short("Huge demon guard");
  set_long("You feel extremely uncomfortable near this big figure. Its shoulders' diameter\n" + 
           "must be some seven feet, and the height is nearing to nine feet. The guard is\n" + 
           "breathing in long, heavy sighs and a deep wheezing sound is coming out from its\n" + 
           "throat with the air. The guard is amazingly muscular, even its arm is more\n" + 
           "stout than your thigh. Demon is holding a huge bone club in its right hand,\n" + 
           "and seems to be ready to use it with almost no reason. You really should be\n" + 
           "aware with this creature here, it does not seem to like you in any possible way.\n");
  set_max_hp(query_hp() + 9000);
  set_hp(query_max_hp());
  set_str(query_str() + 80);
  set_al(-65);
  set_aggressive(0);
  set_resists("fire",90);
  set_skill_chance("tremendous blow", 24);
  set_skill("tremendous blow", 55);
  set_skill("strike", 60);
  set_skill("attack", 100);
  set_skill("bludgeons", 100);
  set_skill("pound", 90);
  set_skill("dodge", 70);
  set_skill("tumble", 50);
  set_skill("weapon parry", 90);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Guard stomps its foot on some small insects running around.\n";
    chat_str[1] = "Guard closely observes your every move.\n";
    chat_str[2] = "Guard coughs noisily.\n";
  }
  load_chat(3, chat_str);

  club = clone_object("/wizards/ahma/castle/eq/boneclub");
  move_object(club, this_object());
  init_command("wield club");
  
  necklace = clone_object("/wizards/ahma/castle/eq/boneneck");
  move_object(necklace, this_object());
  init_command("wear necklace");
  
  plate = clone_object("/wizards/ahma/castle/eq/bonemail");
  move_object(plate, this_object());
  init_command("wear plate");
}
