inherit "obj/monster";
object room;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+18);
  set_name("deer");
  set_alt_name("animal");
  set_alias("walkeri");
  set_short("Frightened forest deer");
  set_long("A frightened animal is running around wildly and attacking everything it\n" + 
           "sees. No obvious instigator for its terrified condition can be seen, but\n" + 
           "something, maybe a hunter, must have scared it very badly. Though the\n" + 
           "animal is very thin and slim, its small but sharp horns make it really\n" + 
           "fierce opponent in combat.\n");
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());  
  set_aggressive(1);
  set_animal();
  set_move_at_random(5+random(15));
  set_str(query_str() + 10);
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
  say("Deer arrives from northeast.\n");
  init_command("sw");
  say("Deer arrives from northeast.\n");
  init_command("w");
  say("Deer arrives from east.\n");
}

wrongroom2() {
  init_command("ne");
  say("Deer arrives from southwest.\n");
  init_command("ne");
  say("Deer arrives from southwest.\n");
}

wrongroom3() {
  init_command("w");
  say("Deer arrives from east.\n");
  init_command("sw");
  say("Deer arrives from northeast.\n");
  init_command("s");
  say("Deer arrives from north.\n");
}

wrongroom4() {
  init_command("n");
  say("Deer arrives from south.\n");
  init_command("n");
  say("Deer arrives from south.\n");
  if(!random(2))
    { init_command("nw"); say("Deer arrives from southeast.\n"); }
    { init_command("ne"); say("Deer arrives from southwest.\n"); }
}


wrongroom5() {
  init_command("ne");
  say("Deer arrives from southeast.\n");
  init_command("n");
  say("Deer arrives from south.\n");
  if(!random(2)) {
    init_command("nw"); say("Deer arrives from southeast.\n"); init_command("e"); say("Deer arrives from east.\n");
    }
    else {
      if(!random(2)) {
      init_command("nw"); say("Deer arrives from southeast.\n"); init_command("nw"); say("Deer arrives from southeast.\n");
      }
      else {
        return 1;
      }
   }
}
