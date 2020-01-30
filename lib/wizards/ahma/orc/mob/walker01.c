inherit "obj/monster";
object room;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+20);
  set_name("woman");
  set_alias("walkeri");
  set_race("orc");
  set_gender(2);
  set_short("An Orcish woman walking in the forest");
  set_long("A good-looking Orcish woman is walking on the forest path, probably to\n" + 
           "keep up her shape. The woman is walking unhurriedly using two wooden\n" + 
           "staves to help her advance and seems to enjoy every moment spent walking\n" + 
           "in the thick, green forest. The woman is wearing clothes suitable for\n" + 
           "excercising.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Woman smiles at you merrily.\n";
    chat_str[1] = "Woman stretches her hands in the air.\n";
    chat_str[2] = "Woman whistles some happy tune while walking.\n";
  }
  load_chat(3, chat_str);
  
  if(!present("joggers", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/joggers"), this_object()); init_command("wear jogger"); }
  if(!present("staff", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/staff"), this_object()); init_command("wield staff"); }
  if(!present("staff 2", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/staff"), this_object()); init_command("wield staff 2"); }
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());
  set_move_at_random(5+random(15));
  set_skill("dodge", 20);
  set_skill("foresee attack", 10);
  set_skill("alertness", 15);
}

monster_died() {
  call_other(room, "mobdead");
  return 0;
}

poproom() {
  room = environment(this_object());
}

checkroom() {
  if(query_current_room() == "/wizards/ahma/orc/village/vil01") {
  call_out("wrongroom1", 1);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for01") {
  call_out("wrongroom2", 4);
  }
  if(query_current_room() == "/wizards/ahma/orc/village/vil14") {
  call_out("wrongroom3", 1);
  }
  if(query_current_room() == "/wizards/ahma/orc/village/vil21") {
  call_out("wrongroom4", 1);
  }
  if(query_current_room() == "/wizards/ahma/orc/village/vil26") {
  call_out("wrongroom5", 1);
  }
}

wrongroom1() { 
  init_command("sw");
  say("Woman arrives from northeast.\n");
  init_command("sw");
  say("Woman arrives from northeast.\n");
  init_command("w");
  say("Woman arrives from east.\n");
}

wrongroom2() {
  init_command("ne");
  say("Woman arrives from southwest.\n");
  init_command("ne");
  say("Woman arrives from southwest.\n");
}

wrongroom3() {
  init_command("w");
  say("Woman arrives from east.\n");
  init_command("sw");
  say("Woman arrives from northeast.\n");
  init_command("s");
  say("Woman arrives from north.\n");
}

wrongroom4() {
  init_command("n");
  say("Woman arrives from south.\n");
  init_command("n");
  say("Woman arrives from south.\n");
  if(!random(2))
    { init_command("nw"); say("Woman arrives from southeast.\n"); }
    { init_command("ne"); say("Woman arrives from southwest.\n"); }
}


wrongroom5() {
  init_command("ne");
  say("Woman arrives from southeast.\n");
  init_command("n");
  say("Woman arrives from south.\n");
  if(!random(2)) {
    init_command("nw"); say("Woman arrives from southeast.\n"); init_command("e"); say("Woman arrives from east.\n");
    }
    else {
      if(!random(2)) {
      init_command("nw"); say("Woman arrives from southeast.\n"); init_command("nw"); say("Woman arrives from southeast.\n");
      }
      else {
        return 1;
      }
   }
}
