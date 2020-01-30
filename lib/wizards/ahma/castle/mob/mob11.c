inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+30);
  set_name("serpent");
  set_alias("demon");
  set_short("Two-headed demon serpent");
  set_long("A fiery serpent is wriggling among the stalactites in this room. Both of its\n" +
           "two eye-pairs are flaming furiously, and the whole figure seems to consist\n" + 
           "of flames. The demon is much bigger than normal snakes, and it reaches higher\n" + 
           "than a normal-sized human, when raising it two heads in the air. At all times,\n" + 
           "the serpent makes annoying hissing voice. From one of its steaming mouths drips\n" + 
           "reddish, definitely hot liquid, maybe some poison to kill its prey. The snake\n" + 
           "moves around the room all the time. Sometimes it opens either of its two mouths\n" + 
           "and bites the air with one quick move, like showing you what it is capable of,\n" + 
           "or maybe to make you scared.\n");
  set_str(query_str()+20);
  set_max_hp(query_hp() + 300);
  set_hp(query_max_hp());
  set_al(-55);
  set_aggressive(0);
  set_resists("fire",100);

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Serpent hisses noisily.\n";
    chat_str[1] = "Serpent wriggles near you on the ground.\n";
    chat_str[2] = "Serpent stares at you hypnotically with all of its four eyes.\n";
  }
  load_chat(3, chat_str);

}