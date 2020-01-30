inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+25);
  set_name("jogger");
  set_alias("walkeri");
  set_alt_name("man");
  set_race("orc");
  set_gender(1);
  set_short("A sweaty Orc jogger");
  set_long("A sweaty Orc is leaning against his knees in the side of the path. Seems\n" + 
           "that this Orc is jogging around the forest and trying to keep himself in\n" + 
           "good shape. At the moment the sweaty man stopped to take a break and trying\n" + 
           "to stabilize his breath. The orc seems to be in very good condition and is\n" + 
           "probably prepared for hostile attacks in the forest.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Jogger huffs frequently.\n";
    chat_str[1] = "Jogger gasps rapidly for air.\n";
    chat_str[2] = "Jogger leers quickly at you.\n";
  }
  load_chat(3, chat_str);
  set_dex(query_dex() * 2);
  if(!present("joggers", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/joggers"), this_object()); init_command("wear joggers"); }
  if(!present("tricots", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/tricots"), this_object()); init_command("wear tricots"); }
  set_move_at_random(2 + random(5));
  set_skill("dodge", 70);
  set_skill("alertness", 60);
  set_skill("foresee attack", 40);
  set_skill("tumble", 35);
  set_skill("doublehit", 40);
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
  say("Jogger arrives from northeast.\n");
  init_command("sw");
  say("Jogger arrives from northeast.\n");
  init_command("w");
  say("Jogger arrives from east.\n");
}

wrongroom2() {
  init_command("ne");
  say("Jogger arrives from southwest.\n");
  init_command("ne");
  say("Jogger arrives from southwest.\n");
}

wrongroom3() {
  init_command("w");
  say("Jogger arrives from east.\n");
  init_command("sw");
  say("Jogger arrives from northeast.\n");
  init_command("s");
  say("Jogger arrives from north.\n");
}

wrongroom4() {
  init_command("n");
  say("Jogger arrives from south.\n");
  init_command("n");
  say("Jogger arrives from south.\n");
  if(!random(2))
    { init_command("nw"); say("Jogger arrives from southeast.\n"); }
    { init_command("ne"); say("Jogger arrives from southwest.\n"); }
}


wrongroom5() {
  init_command("ne");
  say("Jogger arrives from southeast.\n");
  init_command("n");
  say("Jogger arrives from south.\n");
  if(!random(2)) {
    init_command("nw"); say("Jogger arrives from southeast.\n"); init_command("e"); say("Jogger arrives from east.\n");
    }
    else {
      if(!random(2)) {
      init_command("nw"); say("Jogger arrives from southeast.\n"); init_command("nw"); say("Jogger arrives from southeast.\n");
      }
      else {
        return 1;
      }
   }
}
