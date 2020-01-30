inherit "obj/monster";
string tmp, tmp2;
object ob;

reset(arg) {
  object mail;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(5)+32);
  set_name("guard");
  set_race("human");
  set_gender(1);
  set_short("A guard of the castle");
  set_long("It seems obvious that this man has never been on the battlefield before. The\n" + 
           "man is shivering and sweating from fear and is whispering some nutty words.\n" + 
           "The guard is not even dressed like a normal royal guard: He has a plate mail\n" + 
           "on him, but seems to be missing his sword, which belongs to a basic equipment\n" + 
           "of a guard. Although he seems shocked, he looks ready to defend his own life.\n");
  set_max_hp(query_hp() + 20000);
  set_hp(query_max_hp());
  set_str(query_str() + 70);
  set_al(50);
  set_aggressive(0);
  set_skill_chance("kick", 90);

  if(!chat_str) {
    chat_str = allocate(7);
    chat_str[0] = "Guard whispers: 'Keep it quiet.'\n";
    chat_str[1] = "Guard whispers: 'There's something up there.'\n";
    chat_str[2] = "Guard whispers: 'I don't want to die.'\n";
    chat_str[3] = "Guard whispers: 'Have you seen those things?'\n";
    chat_str[4] = "Guard whispers: 'If I would have my precious sword, I would revenge.'\n";
    chat_str[5] = "Guard whispers: 'Have you seen my sparkling sword?'\n";
    chat_str[6] = "Guard whispers: 'That damned Imp took my sword, MY SWORD.'\n";
  }
  load_chat(10, chat_str);

  mail = clone_object("/world/eq/armours/platemail");
  move_object(mail, this_object());
  init_command("wear mail");
}

catch_tell(str) {
  if(sscanf(str,"%s gives %s to you.",tmp, tmp2) == 2) {
  call_out("check1", 2);
  return 1;
  }
}

check1() {
  say("Guard examines " + tmp2 + " carefully.\n");
  call_out("check2", 4);
}

check2() {
  init_command("unwield sword");
  init_command("unwield sword 2");
  init_command("unwield axe");
  init_command("unwield axe 3");
  init_command("unwield dagger");
  init_command("unwield dagger 2");
  init_command("wield blade");
  if(query_right_weapon()) {
  if(query_right_weapon()->query_name() == "short sword") {
  if(query_right_weapon()->query_wc() == 60) {
  ob = find_player(lower_case(tmp));
  if(!ob->query_quests("Return guard his sparkling sword")) {
    tell_object(ob, "You completed quest 'Return guard his sparkling sword'.\n");
    ob->set_quest("Return guard his sparkling sword");
  }
  else {
    tell_object(ob, "You have already completed this quest.\n");
  }
  say("Guard says: 'Thank you very much!'\n");
  call_out("quest1", 3);
  }
  else {
    say("Guard grunts: 'No, this is not my weapon.'\n");
    say("Guard drops something on the ground.\n");
    move_object(present(tmp2, this_object()), environment(this_object()));
    call_out("wrongsw", 3);
    return 1;
  }
  }
  else {
    say("Guard grunts: 'No, this is not my weapon.'\n");
    say("Guard drops something on the ground.\n");
    move_object(present(tmp2, this_object()), environment(this_object()));
    call_out("wrongsw", 3);
    return 1;
  }
}
  else {
    say("Guard grunts: 'No, this is not my weapon.'\n");
    say("Guard drops something on the ground.\n");
    move_object(present(tmp2, this_object()), environment(this_object()));
    call_out("wrongsw", 3);
    return 1;
  }
}

wrongsw() {
  say("Guard eyes you suspiciously.\n");
  return 1;
}

quest1() {
  say("\nGuard says: 'Wait here, I'll go and slay some of those bastards.'\n");
  call_out("quest2", 3);
}

quest2() {
  say("\nGuard leaves up.\n");
  call_other(environment(this_object()), "quest3");
  return 1;
}
