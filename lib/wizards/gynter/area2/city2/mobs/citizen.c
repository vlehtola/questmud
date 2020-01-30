inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(14);
  set_name("citizen");
  set_short("A citizen");
  set_long("The poor citizen is dressed in rags suitable for scarecrows.\n");
  set_al(0);
  set_aggressive(1);
  set_init_ob(this_object());
  set_move_at_reset(1);

  if (!chat_str) {
    chat_str = allocate(2);
    chat_str[0] = "Citizen says: Welcome to our city.\n";
    chat_str[1] = "Citizen says: I hope that you will enjoy your stay here.\n";
  }

  load_chat(80, chat_str);
}

monster_init() {
  if(!this_player()->query_quests("Strakhand, Kill the mage")) { return 1; }
}
