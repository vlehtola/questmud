inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_race("human");
  set_level(18);
  set_name("citizen");
  set_short("A crumbled citizen");
  set_long("The poor citizen is dressed in rags suitable for scarecrows.\n");
  set_al(0);
  set_aggressive(1);
  set_init_ob(this_object());
  set_move_at_reset(1);

  if (!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Citizen says: Welcome to our city.\n";
    chat_str[1] = "Citizen says: I hope that you will enjoy your stay here.\n";
    chat_str[2] = "Citizen says: I get so fed up with this war. I never get any food.\n";
    chat_str[3] = "Citizen says: I remember how it was before the war with Therheran.\n";
  }
  load_chat(80, chat_str);
}

monster_init() {
  if(!this_player()->query_quests("Therheran, Killed king")) { return 1; }
}
