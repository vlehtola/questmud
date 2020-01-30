inherit "obj/monster";
int dead;
string chat_str;
  
reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(9);
  set_name("child");
  set_race("orc");
  set_gender(1);
  if(!dead) { momalive(); } else { momdead(); }

  if(!chat_str) {
    chat_str = allocate(3);
    if(!dead) { normchat(); } else { deadchat(); }
    
  }
  load_chat(3, chat_str);
  set_dead_ob(this_object());
}

monster_died() {
  if(!dead) {
    present("mother", environment(this_object()))->childdead();
    return 0;
  }
  else {
    return 0;
  }
}

normchat() { 
  chat_str[0] = "Child gurgles inanely.\n";
  chat_str[1] = "Child smiles at his mother.\n";
  chat_str[2] = "Child stumbles but his mother prevents just in time him from falling.\n";
}

deadchat() {
  chat_str[0] = "Child asks: 'Hav' yoo seen my mo'?'\n";
  chat_str[1] = "Child cries: 'I want my mommy here!'\n";
  chat_str[2] = "Child sobs: 'Where did she go..'\n";
}

momalive() {
  set_short("An Orcish child is walking with his mother");
  set_long("Young child's face is shining with joy and happiness. Child is walking\n" + 
           "next to his mother who probably has taken him for a walk outside the\n" + 
           "house. The child does not walk very well, but his mother is giving him\n" + 
           "the support needed to prevent him from falling down on the ground.\n");
}

momdead() {
  set_short("A lonely Orcish child is standing here");
  dead = 1;
  set_long("Young child is standing in the middle of the road and crying. Tears\n" + 
           "flow down in rivers on both of his cheeks as he leers helplessly around\n" + 
           "him like trying to find something. Maybe the child has lost something\n" + 
           "dear to him.\n");
  deadchat();
}

catch_tell(str) {
  string who, where;
  if(sscanf(str, "%s leaves %s.", who, where) == 2) {
    if(who == "Mother") {
    call_out("move_to", 1, where);
    return 1;
    }
  }
}

move_to(str) {
init_command(str);
}
