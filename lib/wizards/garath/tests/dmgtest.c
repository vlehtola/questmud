inherit "obj/monster";
void reset(status arg) {
    string *chat_str, *a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_name("dummy");
    set_short("Test dummy");
    set_long("Damage testing dummy.\n");
    set_level(1);
    set_con(100000);
    set_max_hp(1000000);
}

status hit_with_spell(int dam, string dam_type, object ob) {
  say("Damage done: "+dam+" with "+dam_type+"\n");
  this_player()->stop_all();
  stop_all();
  heal_self(dam);
  return 1;
}
