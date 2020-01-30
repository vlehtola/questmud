inherit "obj/monster";
object crystal;
reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+38);
  set_name("regor");
  set_alias("thief");
  set_race("hobbit");
  set_gender(1);
  set_aggressive(1);
  set_short("Regor the pillager and thief");
  set_long("An tiny looking hobbit thief. He is searching something inside this tomb and\n"+
           "mumbling something about crystal of final destruction. He is wearing a dark\n"+
           "cloak and torch in his arms.\n");

  if(!chat_str) {
    chat_str = allocate(1);
    chat_str[0] = "Regor mumbles something about crystal.\n";
  }
  load_chat(3, chat_str);
  set_log();
  set_str(query_str()+300);
  set_max_hp(query_hp() + 30000);
  set_hp(query_max_hp());
  crystal = clone_object("/wizards/neophyte/city/obj/crystal");
  move_object(crystal, this_object());
}
