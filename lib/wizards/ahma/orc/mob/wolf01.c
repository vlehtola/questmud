inherit "obj/monster";
int i = random(5), h, p;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+23);
  set_name("wolf leader");
  set_alias("wolf");
  set_alt_name("leader");
  set_short("A leader wolf of the pack");
  set_long("A strong-looking leader of the pack of wolves wandering around the forest.\n" +
           "Leader's eyes glitter as it tries to find some prey suitable for food in\n" + 
           "its surroundings. The leader wolf's tail is waving in the air all the times\n" + 
           "to show the others its leadership.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Wolf leader glares at you angrily.\n";
    chat_str[1] = "Wolf leader swings its silvery tail in the air.\n";
    chat_str[2] = "Wolf leader growls loudly.\n";
  }
  load_chat(3, chat_str);
  
  set_animal();
  set_dead_ob(this_object());
  set_special(99);
  set_skill("dodge", 30);
  set_skill("foresee attack", 20);
  set_skill("alertness", 30);
  if(!p) { call_out("clonewolf", 1, i+1); }
}

monster_died() {
  destwolf(p);  
  return 0;
}

special_move() {
  object ob;
  if(!h) {
  ob = this_object()->query_attack();
  tell_room(environment(this_object()), "As the leader is attacked, the whole pack runs for the attacker.\n");  
  h++;
  if(p==1) { present("minion", environment(this_object()))->attack_object(ob); }
  if(p==2) { present("minion 2", environment(this_object()))->attack_object(ob); present("minion", environment(this_object()))->attack_object(ob); }
  if(p==3) { present("minion 3", environment(this_object()))->attack_object(ob); present("minion 2", environment(this_object()))->attack_object(ob); present("minion", environment(this_object()))->attack_object(ob); }
  if(p==4) { present("minion 4", environment(this_object()))->attack_object(ob); present("minion 3", environment(this_object()))->attack_object(ob); present("minion 2", environment(this_object()))->attack_object(ob); present("minion", environment(this_object()))->attack_object(ob); }
  if(p==5) { present("minion 5", environment(this_object()))->attack_object(ob); present("minion 4", environment(this_object()))->attack_object(ob); present("minion 3", environment(this_object()))->attack_object(ob); present("minion 2", environment(this_object()))->attack_object(ob); present("minion", environment(this_object()))->attack_object(ob); }
  }
}


clonewolf(i) {
  i--; p++;
  move_object(clone_object("/wizards/ahma/orc/mob/wolf02"), environment(this_object()));
  if(i<1) { return; } { call_out("clonewolf", 1, i); }
}

reducewolf() {
  p--;
}

destwolf(p) {
  if(p==0) { return; }
  if(p==1) { tell_room(environment(this_object()), "The other wolves from the pack scatter in the woods as their leader is slain.\n"); destruct(present("minion", environment(this_object()))); }
  if(p==2) { tell_room(environment(this_object()), "The other wolves from the pack scatter in the woods as their leader is slain.\n"); destruct(present("minion 2", environment(this_object()))); destruct(present("minion", environment(this_object()))); }
  if(p==3) { tell_room(environment(this_object()), "The other wolves from the pack scatter in the woods as their leader is slain.\n"); destruct(present("minion 3", environment(this_object()))); destruct(present("minion 2", environment(this_object()))); destruct(present("minion", environment(this_object()))); }
  if(p>3) { return; }
}

test() {
  return p;
}
