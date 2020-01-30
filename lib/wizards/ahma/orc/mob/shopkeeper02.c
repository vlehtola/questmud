inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 40);
  set_name("nadia");
  set_alias("woman");
  set_alt_name("owner");
  set_short("Nadia, the owner of flower shop");
  set_gender(2);
  set_race("orc");
  set_long("This Orcish woman is wearing a pink dress which makes her look too young\n" + 
           "for her age. Woman has a begging look on her face, she still seems to be\n" + 
           "a single. Nadia owns a flower shop in Nehelam and seems to get along with\n" + 
           "flowers much better than with men. Her muscular, hairy arms indicate that\n" + 
           "that she has even prepared to defend her precious flowers against thieves\n" +
           "and other troublemakers.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Nadia blinks her eye to you insinuately.\n";
    chat_str[1] = "Nadia asks: 'You care to buy some flowers from me?'\n";
    chat_str[2] = "Nadia smiles heartbreakingly at you.\n";
  }
  load_chat(3, chat_str);

  set_max_hp(query_hp() + 8000);
  set_hp(query_max_hp());
  set_str(query_str() + 20);
  set_int(query_int() + 50);

  if(!present("crown", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/flowercrown"), this_object()); init_command("wear crown"); }
  if(!present("dress", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/dress"), this_object()); init_command("wear dress"); }
  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/salerobes"), this_object()); init_command("wear robes"); }
  if(!present("staff", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/staff"), this_object()); init_command("wield staff"); }
  set_mage();
  set_spell_chance(15, "exs brr strm");
  set_skill("mana control", 50);
  set_skill("cast essence", 50);
  set_skill("cast ice", 50);
  set_skill("cast storm", 40);
  set_skill("chanting", 40);
  set_skill("lore of cold", 30);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("foresee attack", 25);
  set_skill("alertness", 35);
  set_skill("tumble", 10);
  set_skill("tremendous blow", 30);
  set_skill_chance("tremendous blow", 10);
  set_skill("kick", 75);
  set_skill_chance("kick", 45);
  set_log();
  set_al(30);
}
