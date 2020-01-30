inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+30);
  set_name("ranger");
  set_race("orc");
  set_gender(1);
  set_short("An Orcish ranger dressed in green");
  set_long("Angry and strong-looking ranger is standing in the path. This small\n" + 
           "green man has thick black mustache and he looks quite experienced.\n" + 
           "Often every forests have their own rangers who know everything about\n" + 
           "the surrounding forest. This man seems to be one of those rangers.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Ranger grunts: 'You know, this is my forest.'\n";
    chat_str[1] = "Ranger eyes at you angrily.\n";
    chat_str[2] = "Ranger says: 'Get out of my forest, you fool.'\n";
  }
  load_chat(3, chat_str);
  set_max_hp(query_hp() + 600);
  set_hp(query_max_hp());  

  if(!present("hood", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/greenhood"), this_object()); init_command("wear hood"); }
  if(!present("shirt", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/greenshirt"), this_object()); init_command("wear shirt"); }
  if(!present("knife", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/knife"), this_object()); init_command("wield knife"); }
  if(!present("knife 2", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/knife"), this_object()); init_command("wield knife 2"); }
  set_skill("two weapons combat", 100);
  set_skill("dodge", 40);
  set_skill("alertness", 20);
  set_skill("foresee attack", 15);
  set_skill("parry", 40);
  set_skill("weapon parry", 20);
  set_skill("tumble", 10);
  set_skill("doublehit", 20);
  set_skill("kick", 80);
  set_skill_chance("kick", 40);
}