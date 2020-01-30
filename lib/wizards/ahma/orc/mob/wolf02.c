inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+18);
  set_name("wolf");
  set_alt_name("minion");
  set_short("A gray forest wolf");
  set_long("This wolf is a member of a wolf pack living in this forest. It is loyally\n" + 
           "following the pack's leader to hunt down some prey for the pack to eat.\n" + 
           "Wolf's tongue is hanging out from the mouth as it tries to cool itself down.\n" + 
           "The sharp set of white teeth can be seen in the wolf's mouth. The wolf's\n" + 
           "tail is hanging between its rear legs to show respect for the pack leader.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Wolf whines softly.\n";
    chat_str[1] = "Wolf walks around nervously.\n";
    chat_str[2] = "Wolf looks at you and lowers its head.\n";
  }
  load_chat(3, chat_str);
  
  set_animal();
  set_dead_ob(this_object());
  set_skill("dodge", 20);
}

monster_died() {
  if(present("leader", environment(this_object()))) {
  present("leader", environment(this_object()))->reducewolf();
  }
  return 0;
}
