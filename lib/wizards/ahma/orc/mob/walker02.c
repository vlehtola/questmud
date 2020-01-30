//Fixed by Rag, changed int dead to int is_dead because dead already existed in obj/living
inherit "obj/monster";
int is_dead, i, h;
string chat_str;
object room;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+21);
  set_name("mother");
  set_alias("woman");
  set_race("orc");
  set_gender(2);
  if(!is_dead) { childalive(); } else { childdead(); }

  if(!chat_str) {
    chat_str = allocate(3);
    if(!is_dead) { normchat(); } else { deadchat(); }
  }
  load_chat(3, chat_str);  
  if(!i) { call_out("clonechild", 1); i++; }
  if(!h) { call_out("poproom", 1); h++; }
  if(!present("dress", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/dress"), this_object()); init_command("wear dress"); }
  set_dead_ob(this_object());
  set_move_at_random(5+random(15));
}

monster_died() {
  if(!is_dead) {
    present("child", environment(this_object()))->momdead();
    call_other(room, "childdead");
    return 0;
  }
  else {
  return 0;
  }
}

normchat() {
  chat_str[0] = "Woman smiles at her child.\n";
  chat_str[1] = "Woman whispers something to her child.\n";
  chat_str[2] = "Woman looks happy.\n";
}

deadchat() {
  chat_str[0] = "Woman cries: 'Oh my god! OH MY GOD! Where's my little child!?'\n";
  chat_str[1] = "Woman says: 'I looked just a second away and he's already gone.'\n";
  chat_str[2] = "Woman sobs: 'Oh lord! Please, you, help me to find my beloved child.'\n";
}

childalive() {
  set_short("An Orcish woman is walking her child");
  set_long("Quite plump Orcish woman is staring at the road ahead of her. Soft smile\n" + 
           "can be seen on her pink lips as she keeps her child from his hand and\n" + 
           "walks him around. The woman is wearing a dress. Brownish hair can be seen\n" + 
           "growing from her arms.\n");
  return;
}

childdead() {
  is_dead = 1;
  set_short("An Orcish woman is standing here");
  set_long("Quite plump Orcish woman is leering at her surroundings. Woman looks both\n" + 
           "sad and angry at the same time, almost like she had lost something dear.\n" + 
           "The woman is wearing a dress. Black hair can be seen growing from her arms.\n");
  deadchat();
  set_move_at_random(0);
  return;
}

clonechild() {
  move_object(clone_object("/wizards/ahma/orc/mob/walker03"), environment(this_object()));  
}

poproom() {
  room = environment(this_object());
}