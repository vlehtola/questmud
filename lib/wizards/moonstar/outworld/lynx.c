inherit "obj/monster";
object room;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+28);
  set_name("lynx");
  set_alt_name("animal");
  set_alias("walkeri");
  set_short("A black-spotted lynx");
  set_long("Very pride and big cat-animal is walking along the forest path. The lynx\n" + 
           "is almost as big as an adult sheep. The strength can be sensed running in\n" + 
           "the veins of its big paws. The black tufts in the tips of lynx's ears\n" + 
           "look fascinating, the lynx is coloured in mild brown.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Lynx walks around pridefully.\n";
    chat_str[1] = "Lynx strokes its hair with its furry paw.\n";
    chat_str[2] = "Lynx purrs at you.\n";
  }
  load_chat(3, chat_str);
  
  set_max_hp(query_hp() + 300);
  set_hp(query_max_hp());
  set_str(query_str() + 20);
  set_animal();
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());  
  set_move_at_random(5+random(15));

  set_skill("dodge", 40);
  set_skill("alertness", 30);
  set_skill("foresee attack", 15);
  set_skill("tumble", 15);
  set_skill("doublehit", 20);
  set_al(10);
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
  say("Lynx arrives from northeast.\n");
  init_command("sw");
  say("Lynx arrives from northeast.\n");
  init_command("w");
  say("Lynx arrives from east.\n");
}

wrongroom2() {
  init_command("ne");
  say("Lynx arrives from southwest.\n");
  init_command("ne");
  say("Lynx arrives from southwest.\n");
}

wrongroom3() {
  init_command("w");
  say("Lynx arrives from east.\n");
  init_command("sw");
  say("Lynx arrives from northeast.\n");
  init_command("s");
  say("Lynx arrives from north.\n");
}

wrongroom4() {
  init_command("n");
  say("Lynx arrives from south.\n");
  init_command("n");
  say("Lynx arrives from south.\n");
  if(!random(2))
    { init_command("nw"); say("Lynx arrives from southeast.\n"); }
    { init_command("ne"); say("Lynx arrives from southwest.\n"); }
}


wrongroom5() {
  init_command("ne");
  say("Lynx arrives from southeast.\n");
  init_command("n");
  say("Lynx arrives from south.\n");
  if(!random(2)) {
    init_command("nw"); say("Lynx arrives from southeast.\n"); init_command("e"); say("Lynx arrives from east.\n");
    }
    else {
      if(!random(2)) {
      init_command("nw"); say("Lynx arrives from southeast.\n"); init_command("nw"); say("Lynx arrives from southeast.\n");
      }
      else {
        return 1;
      }
   }
}
