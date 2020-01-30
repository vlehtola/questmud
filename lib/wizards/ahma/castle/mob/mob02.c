inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(6)+22);
  set_name("demon");
  set_alias("lesser");
  set_short("Lesser fire demon");
  set_long("The demon here seems to be somewhat bigger than the other demons commonly\n" + 
           "seen around the castle. Its face is very dark and no feelings can be inter-\n" + 
           "preted from it. Though you can sense that the creature feels confident and is\n" + 
           "ready for battle when necessary. The demon does not burn as intensively as its\n" + 
           "smaller kins, but the bigger size and muscular arms make it look much more\n" + 
           "dangerous than the more burning ones.\n" + 
           "The monster has no visible armour and it seems to fight bare handed.\n");
  set_al(-50);
  set_aggressive(0);
  set_resists("fire",100);
  set_skill_chance("kick", 80);
  set_skill("kick", 80);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Fire demon looks at its knuckles.\n";
    chat_str[1] = "Fire demon kicks small rocks lying on the ground.\n";
    chat_str[2] = "Fire demon twiddles its thumbs.\n";
  }
  load_chat(3, chat_str);  
}
