inherit "obj/monster";
int i, h, t;
object plr, plr2;
string who;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+15);
  set_name("boy");
  set_race("orc");
  set_gender(1);
  set_short("An Orcish boy");
  set_long("A young Orcish boy seems to enjoy from his childhood. This small, green\n" + 
           "figure has somewhat reddish cheeks and little drops of sweat run down on\n" + 
           "his forehead and temples which are partly covered with dirty hair. The\n" + 
           "child seems to be constantly on the move, which is not a peculiar sight\n" +
           "among the kids in this village.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Boy giggles inanely.\n";
    chat_str[1] = "Boy scratches his head idly.\n";
    chat_str[2] = "Boy eyes at you and smiles.\n";
  }
  load_chat(3, chat_str);

  if(!i) { i++; call_out("game1", 2); }
  set_skill("dodge", 100);
  set_skill("foresee attack", 100);
  set_skill("alertness", 100);
  set_skill("tumble", 100);
}

catch_tell(str) {
  if(sscanf(str, "%s arrives", who) == 1) {
    plr2 = find_player(lower_case(who));
    if((plr2->query_name()) != (plr->query_name())) { call_out("wrongplr", 3); return 1; } else
    { call_out("move_to", 2);
    return 1;
    }
  }
}

move_to() {
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/house03" || this_object()->query_current_room() == "/wizards/ahma/orc/village/house07") {
    say("Boy congratulates: 'Very good! Let's try another place in the village.'\n");
    if(!h) { plr->add_exp(100000 + random(50001)); h++; }
    call_out("complete1", 2);
    return 1;
  }
  
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/wagons" || this_object()->query_current_room() == "/wizards/ahma/orc/village/tent01") {
    say("Boy congratulates: 'Excellent! Now I'm going to hide myself somewhere in the forest. Haha!'\n");
    if(!h) { plr->add_exp(300000 + random(75001)); h++; }
    call_out("complete2", 2);
    return 1;
  }

  if(this_object()->query_current_room() == "/wizards/ahma/orc/forest/for35" || this_object()->query_current_room() == "/wizards/ahma/orc/forest/for14") {
    say("Boy congratulates: 'Most impressive! I will hide myself one more time in the forest. This one is really hard!'\n");
    if(!h) { plr->add_exp(1500000 + random(200001)); h++; }
    call_out("complete3", 2);
    return 1;
  }
}

game1() {
  say("\nBoy whines: 'Ouch! Why did you drop me down?'\n");
  call_out("game2", 2);
  return 1;
}

game2() {
  say("\nBoy says: 'Now YOU will have to play with me!'\n");
  call_out("game3", 2);
  return 1;
}

game3() {
  say("\nBoy says: 'Just try to find me! I will hide myself somewhere in the village.'\n");
  call_out("game4", 2);
  return 1;
}

game4() {
  say("\nBoy leaves south.\n");
  if(plr) {
  if(!random(2)) {
  move_object(this_object(), "/wizards/ahma/orc/village/house03"); }
  else {
  move_object(this_object(), "/wizards/ahma/orc/village/house07"); }
  }
  return 1;
}

setplr(ob) {
  plr = ob;
}

complete1() {
  h--;
  say("Boy leaves south.\n");
  if(plr) {
  if(!random(2)) {
  move_object(this_object(), "/wizards/ahma/orc/village/wagons"); }
  else {
  move_object(this_object(), "/wizards/ahma/orc/village/tent01"); }
  }
}

complete2() {
  h--;
  say("Boy leaves out.\n");
  if(plr) {
  if(!random(2)) {
  move_object(this_object(), "/wizards/ahma/orc/forest/for35"); }
  else {
  move_object(this_object(), "/wizards/ahma/orc/forest/for14"); t = 1; }
  }
}

complete3() {
  h--;
  if(!t) { say("Boy leaves northwest.\n"); } else { say("Boy leaves east.\n"); }
  if(plr) { move_object(this_object(), "/wizards/ahma/orc/void"); }
  call_other("/wizards/ahma/orc/forest/for11", "setevent");
  call_other("/wizards/ahma/orc/forest/for11", "boyevent", plr);
}

complete4() {
  say("Boy congratulates: 'This is hard to believe. You really are a master-tracker!\n");
  if(!h) { plr->add_exp(3250000 + random(250001)); h++; }
  call_out("complete5", 2);
}

complete5() {
  say("Boy says: 'I'm going to play with my other friends now. Let's play again sometime, bye!\n");
  call_out("finished", 2);
}

finished() {
  say("Boy leaves northeast.\n");
  if(plr) { destruct(this_object()); }
}

wrongplr() {
  if(plr) { say("Boy points at " + who + " and says: 'I'm not playing with you, I'm playing with " + plr->query_name() + ".'\n"); }
}
