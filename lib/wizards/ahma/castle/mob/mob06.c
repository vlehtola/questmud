inherit "obj/monster";

reset(arg) {
  object katana, wraps;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+26);
  set_name("ninja");
  set_alias("demon");
  set_short("Black demon ninja");
  set_long("This small sized creature cannot keep himself in one spot for more than a\n" + 
           "few seconds. It is moving constantly, either running around the room or just\n" + 
           "kicking the walls or a body in the floor. In spite of its childishness, this\n" + 
           "creature is no way inexperienced. From time to time the demon practices some\n" + 
           "moves with its sharp katana, and it really seems to know how to handle one:\n" + 
           "The katana moves in speed of lightning and quickly opens some new wounds to\n" + 
           "already dead body on the ground. Though the creature is moving and practising\n" + 
           "all the time, you are sure that it has already marked your presence.\n");
  set_al(-52);
  set_aggressive(0);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Ninja runs on the walls.\n";
    chat_str[1] = "Ninja does some backflips.\n";
    chat_str[2] = "Ninja touches the handle of its katana.\n";
  }
  load_chat(3, chat_str);

  set_resists("fire",45);

  katana = clone_object("/wizards/ahma/castle/eq/katana");
  move_object(katana, this_object());
  init_command("wield katana");
  
  wraps = clone_object("/wizards/ahma/castle/eq/wraps");
  move_object(wraps, this_object());
  init_command("wear wrappings");
}