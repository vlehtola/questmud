inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+25);
  set_name("g'ralt");
  set_alt_name("elder");
  set_alias("man");
  set_gender(1);
  set_race("orc");
  set_short("G'ralt, the respected Orcish elder");
  set_long("An old Orcish man is sitting on a wooden chair. His age seems to be\n" + 
           "already a burden to this hump figure. Orc's head is covered with grayish\n" + 
           "beard and hair, his eyes look very tired. This elderly man is said to\n" + 
           "be one of the oldest Orcs in Deleria, and when examining him, it seems\n" + 
           "quite obvious. G'ralt is respected among other Orcs for his age. The old\n" + 
           "man is holding a walking stick in his right hand.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "G'ralt coughs quietly in his hand.\n";
    chat_str[1] = "G'ralt knocks the floor with his walking stick.\n";
    chat_str[2] = "G'ralt mumbles: 'What the hell are you doing here?'\n";
  }
  load_chat(3, chat_str);

  if(!present("robes", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/graltrobes"), this_object()); init_command("wear robes"); }
  if(!present("stick", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/stick"), this_object()); init_command("wield stick"); }

  set_mage();
  set_spell_chance(40, "exs fla strm");
  set_skill("mana control", 40);
  set_skill("cast essence", 70);
  set_skill("cast fire", 80);
  set_skill("knowledge of heat", 50);
  set_skill("cast storm", 60);
  set_skill("chanting", 50);
  set_skill("parry", 100);
  set_skill("alertness", 80);
  set_skill("foresee attack", 60);
  set_dex(query_dex() - 40);
  set_al(10);
}
