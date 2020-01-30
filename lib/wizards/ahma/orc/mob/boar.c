inherit "obj/monster";
object room;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+25);
  set_name("wild boar");
  set_alias("walkeri");
  set_alt_name("boar");
  set_short("Roaring wild boar");
  set_long("The long, sharp and dirty eyeteeth are definitely the first things that\n" + 
           "catch attention in this ugly animal. The boar is grunting angrily all the\n" + 
           "time, making the atmosphere near the animal uncomfortable. Now and then\n" + 
           "the pig-like creature stomps its foot on the ground, like trying to act\n" +
           "like a boss.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Wild boar stomps the ground with its cloven hoof.\n";
    chat_str[1] = "Wild boar roars at you angrily.\n";
    chat_str[2] = "Wild boar makes out some angry whizzing sounds.\n";
  }
  load_chat(3, chat_str);
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());  
    
  set_animal();
  set_move_at_random(5+random(15));
  set_al(-15);
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
  say("Wild boar arrives from northeast.\n");
  init_command("sw");
  say("Wild boar arrives from northeast.\n");
  init_command("w");
  say("Wild boar arrives from east.\n");
}

wrongroom2() {
  init_command("ne");
  say("Wild boar arrives from southwest.\n");
  init_command("ne");
  say("Wild boar arrives from southwest.\n");
}

wrongroom3() {
  init_command("w");
  say("Wild boar arrives from east.\n");
  init_command("sw");
  say("Wild boar arrives from northeast.\n");
  init_command("s");
  say("Wild boar arrives from north.\n");
}

wrongroom4() {
  init_command("n");
  say("Boar arrives from south.\n");
  init_command("n");
  say("Boar arrives from south.\n");
  if(!random(2))
    { init_command("nw"); say("Boar arrives from southeast.\n"); }
    { init_command("ne"); say("Boar arrives from southwest.\n"); }
}


wrongroom5() {
  init_command("ne");
  say("Boar arrives from southeast.\n");
  init_command("n");
  say("Boar arrives from south.\n");
  if(!random(2)) {
    init_command("nw"); say("Boar arrives from southeast.\n"); init_command("e"); say("Boar arrives from east.\n");
    }
    else {
      if(!random(2)) {
      init_command("nw"); say("Boar arrives from southeast.\n"); init_command("nw"); say("Boar arrives from southeast.\n");
      }
      else {
        return 1;
      }
   }
}
