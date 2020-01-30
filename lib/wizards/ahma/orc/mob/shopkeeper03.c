inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 60);
  set_name("naglah");
  set_alias("man");
  set_alt_name("owner");
  set_short("Naglah, the owner of antique shop");
  set_gender(1);
  set_race("orc");
  set_long("Naglah is a huge Orc whose arms are loaded full of pure strength. It\n" + 
           "almost looks like he would be able to slay dragons by himself if he\n" + 
           "tried. Naglah is rumoured to have been a mighty Paladin couple decades\n" +
           "ago, but nowadays he owns and runs the famous artifact shop in village\n" + 
           "Nehelam. In his shop, Naglah is selling the artifacts which he had\n" + 
           "achieved during his days as a Paladin.\n");
  
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Naglah says: 'I was once a Warrior of Light, but those days are long gone now.'\n";
    chat_str[1] = "Naglah hunts some bugs down from his hairy arms.\n";
    chat_str[2] = "Naglah polishes some accessories on the shelves.\n";
    chat_str[3] = "Naglah suggests: 'I have a list of my wares right here, care to take a look?'\n";
  }
  load_chat(3, chat_str);

  set_max_hp(query_hp() + 200000);
  set_hp(query_max_hp());

  if(!present("plate", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/unget01"), this_object()); init_command("wear plate"); }
  if(!present("helm", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/unget02"), this_object()); init_command("wear helm"); }
  if(!present("boots", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/unget03"), this_object()); init_command("wear boots"); }
  if(!present("leggings", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/unget04"), this_object()); init_command("wear leggings"); }
  if(!present("gauntlets", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/unget05"), this_object()); init_command("wear gauntlets"); }
  set_str(query_str() * 10);
  set_skill("tumble", 100);
  set_skill("dodge", 100);
  set_skill("reflect spell", 100);
  set_skill("counter spell", 100);
  set_skill("round blow", 100);
  set_skill_chance("round blow", 100);
  set_skill("tremendous blow", 100);
  set_skill_chance("tremendous blow", 100);
  set_log();
  set_aggressive(0);
}