inherit "obj/monster";
int h = random(4), i;
object room;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+13);
  set_name("dog");
  set_alias("walkeri");
  set_alt_name("animal");
  
  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Dog sniffs the ground.\n";
    chat_str[1] = "Dog looks at you consideringly.\n";
    chat_str[2] = "Dog swings its tail in the air.\n";
  }
  load_chat(3, chat_str);
  
  if(h==0) { set_short("A hungry dog is begging for food"); long1(); chat_str[3] = "Dog whines at you beggingly.\n"; }
  if(h==1) { set_short("A weak-looking dog is lying on the ground"); long1(); chat_str[3] = "Dog sighs tiredly on the ground.\n";}
  if(h==2) { set_short("A slim dog is sitting on the ground"); long1(); chat_str[3] = "Dog rises its front leg at you.\n"; }
  if(h==3) { set_short("An angry dog is growling at you"); set_level(17 + random(4)); long2(); chat_str[3] = "Dog barks angrily at you.\n"; }

  set_animal();
  if(!i) { call_out("poproom", 1); i++; }
  set_dead_ob(this_object());
  set_move_at_random(5 + random(15));
}

monster_died() {
  call_other(room, "childdead");
  return 0;
}
  
long1() { 
  set_long("This dog seems to be in very bad condition. It does not seem to be owned by\n" + 
           "anyone, maybe it has been abandoned from its former home. Dog's hair is very\n" + 
           "long and dirty and it seems that the animal has not been taken care of in a\n" + 
           "long time. Under its thick hair the dog is very slim, which indicates of mal-\n" +
           "nutrition.\n");
}

long2() {
  set_long("A huge dog is standing still, constantly growling angrily. Dog looks well\n" + 
           "fed and taken care of. Its hair has been cut not too long ago and no dirt\n" + 
           "or stains can be seen in it. Growling dog looks dangerous with its big-\n" + 
           "sized body and sharp set of teeth.\n");
}

poproom() {
  room = environment(this_object());
}

checkroom() {
  if(query_current_room() == "/wizards/ahma/orc/forest/for03") {
    call_out("wrongroom1", 3);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for17") {
    call_out("wrongroom2", 3);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for18") {
    call_out("wrongroom3", 3);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for31") {
    call_out("wrongroom4", 3);
  }
}

wrongroom1() {
  init_command("ne");
  say("Dog arrives from southwest.\n");
  init_command("n");
  say("Dog arrives from south.\n");
}

wrongroom2() {
  init_command("e");
  say("Dog arrives from west.\n");
}

wrongroom3() {
  init_command("s");
  say("Dog arrives from north.\n");
}

wrongroom4() {
  init_command("sw");
  say("Dog arrives from northeast.\n");
}