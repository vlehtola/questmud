inherit "obj/monster";
object room;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+33);
  set_name("bear");
  set_alt_name("animal");
  set_alias("walkeri");
  set_short("A grizzly bear");
  set_long("A grizzly bear is a feared prey among the hunters. Its strong paws\n" + 
           "with sharp claws and thick fur and skin make it a fearful opponent\n" + 
           "when being in close combat with it. The bear seems to be shuffling\n" + 
           "along the forest and enjoying its time. Though it seems to be sturdy\n" + 
           "enough to defend itself if its life would be endangered.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Bear digs a small hole in the ground with its paws.\n";
    chat_str[1] = "Bear roars softly at you.\n";
    chat_str[2] = "Bear sniffs the fresh forest air.\n";
  }
  load_chat(3, chat_str);
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());  
    
  set_max_hp(query_hp() + 1024);
  set_hp(query_max_hp());
  set_str(query_str() + 50);
  set_animal();
  set_move_at_random(5+random(15));
  set_al(20);
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
  say("Bear arrives from northeast.\n");
  init_command("sw");
  say("Bear arrives from northeast.\n");
  init_command("w");
  say("Bear arrives from east.\n");
}

wrongroom2() {
  init_command("ne");
  say("Bear arrives from southwest.\n");
  init_command("ne");
  say("Bear arrives from southwest.\n");
}

wrongroom3() {
  init_command("w");
  say("Bear arrives from east.\n");
  init_command("sw");
  say("Bear arrives from northeast.\n");
  init_command("s");
  say("Bear arrives from north.\n");
}

wrongroom4() {
  init_command("n");
  say("Bear arrives from south.\n");
  init_command("n");
  say("Bear arrives from south.\n");
  if(!random(2))
    { init_command("nw"); say("Bear arrives from southeast.\n"); }
    { init_command("ne"); say("Bear arrives from southwest.\n"); }
}


wrongroom5() {
  init_command("ne");
  say("Bear arrives from southeast.\n");
  init_command("n");
  say("Bear arrives from south.\n");
  if(!random(2)) {
    init_command("nw"); say("Bear arrives from southeast.\n"); init_command("e"); say("Bear arrives from east.\n");
    }
    else {
      if(!random(2)) {
      init_command("nw"); say("Bear arrives from southeast.\n"); init_command("nw"); say("Bear arrives from southeast.\n");
      }
      else {
        return 1;
      }
   }
}
