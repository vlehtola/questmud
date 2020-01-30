inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5) + 33);
  set_name("guard");
  set_alias("man");
  set_gender(1);
  set_race("orc");
  set_short("A huge Orc guarding the chief's house");
  set_long("A big-sized Orc has been hired to guard Chief Tas'gand's hut. Orc\n" + 
           "looks very sturdy and strong with its wooden armour. The guard eyes\n" + 
           "around him with an angry look on his face, just like the guards are\n" + 
           "expected to do. Though the Orc seems to like his job, its being\n" + 
           "indicates of extreme boredness.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Guard looks bored.\n";
    chat_str[1] = "Guard picks his nose, but when he notices that you are watching he quickly stops.\n";
    chat_str[2] = "Guard shifts his weight from one foot to the other.\n";
  }
  load_chat(3, chat_str);

  set_max_hp(query_hp() + 2500);
  set_hp(query_max_hp());
  set_str(query_str() + 80);
  set_skill("parry", 80);
  set_skill("dodge", 40);
  set_skill("foresee attack", 60);
  set_skill("alertness", 80);
  set_skill("tumble", 60);
  set_skill("critical", 70);
  set_skill("enhance criticals", 60);
  set_skill("deceived attack", 50);
  set_skill("cut", 80);
  set_skill("axes", 100);
  set_skill("kick", 100);
  set_skill_chance("kick", 70);
  set_block_dir("east");

  if(!present("mail", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/woodmail"), this_object()); init_command("wear mail"); }
  if(!present("axe", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/steelaxe"), this_object()); init_command("wield axe"); }
  if(!present("shield", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/shield"), this_object()); init_command("wield shield"); }
  set_al(-40);
}

catch_tell(str) {
  string plr;
  object ob;
  if(sscanf(str, "%s arrives from the east", plr) == 1) {
    ob = find_player(lower_case(plr));
    if(!ob) { return; }
    say("Guard shouts: 'How the hell did you get in there?'\n");
    attack_object(ob);
  }
}
