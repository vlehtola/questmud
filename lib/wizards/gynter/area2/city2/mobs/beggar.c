inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(14);
  set_name("beggar");
  set_short("A poor beggar");
  set_long("The poor beggar sitting here with only the dirt as clothes.\n");
  set_al(0);
  set_aggressive(1);
  set_init_ob(this_object());

  if (!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Beggar says: Can you spare some money?\n";
    chat_str[1] = "Beggar says: Please kind sir, give me some money.\n";
    chat_str[2] = "Beggar screams in agony as he realises that you won't give him any money";
  }

  load_chat(60, chat_str);
}

monster_init() {
  if(!this_player()->query_quests("Strakhand, Kill the mage")) { return 1; }
}
