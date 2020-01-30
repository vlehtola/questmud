inherit "obj/monster";
int i;

reset(arg) {
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(15 + random(3));
  set_name("adult yeti");
  set_alias("yeti");
  set_alt_name("adult");
  set_race("yeti");
  set_short("An adult yeti is scouting around the frozen pond");
  set_long("Very big and hairy creature. The adult yeti is almost seven feet\n" +
           "high and is covered in humongous amount of thick fur. Creature's\n" +
           "eyes can be seen in the hairy face, watching alertedly. Yeti lets\n" +
           "out some deep wheezes as it breathes the cold air. The big\n" +
           "creature must possess some strength in its hairy arms.\n");  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Adult yeti blows some cold air towards you.\n";
    chat_str[1] = "Adult yeti walks in circles boredly.\n";
    chat_str[2] = "Adult yeti takes some snow in its hand, but soon drops it back on the ice.\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Adult yeti tries to bounce your head with its huge fist, but misses.\n";
    a_chat_str[1] = "Adult yeti grins with an insane look on its face.\n";
  }
  
  load_chat(3, chat_str);
  load_a_chat(10, a_chat_str);
  set_resists("cold", 80);
  if(!i) set_special(30);
}

special_move() {
  i = 1;
  say("Adult yeti grabs some snow in its hands and starts making a snowball out of it.\n");
  call_out("throwball", 3 + random(3));
  return 1;
}

throwball() {
  say("Adult yeti completes the snowball and throws it towards " + query_attack()->query_name() + "'s direction.\n");
  if(!random(3)) {
    tell_object(query_attack(), "The snowball hits you straight in the face!\n");
    query_attack()->hit_with_spell(10 + random(21));
    say("The snowball hits " + query_attack()->query_name() + " in the face!\n", query_attack());
    i = 0;
  }
  else {
    say("The snowball misses its target and shatters into pieces on the ice.\n");
    i = 0;
  }
  return 1;
}

specname() {
  set_short("An adult yeti is wandering along the tunnels");
}
