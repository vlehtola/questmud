inherit "obj/monster";
object room;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+23);
  set_name("man");
  set_alias("walkeri");
  set_race("orc");
  set_gender(1);
  set_short("An Orcish man is walking on the street");
  set_long("A common-looking Orcish man is walking on the street. The man is walking\n" + 
           "a bit hurriedly, which indicates that he is heading to some particular\n" + 
           "place in the village. The man is wearing a simple Orcish clothing: A shirt\n" + 
           "and shorts. Somewhat muscular arms reach out from the shirt's sleeves.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Man whistles a happy tune.\n";
    chat_str[1] = "Man looks at his feet idly.\n";
    chat_str[2] = "Man quickly twiddles his thumbs.\n";
  }
  load_chat(3, chat_str);  
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());
  set_move_at_random(5 + random(15));
  if(!present("shirt", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/greenshirt"), this_object()); init_command("wear shirt"); }
  if(!present("shorts", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/shorts"), this_object()); init_command("wear shorts"); }
}

monster_died() {
  call_other(room, "childdead");
  return 0;
}

poproom() {
  room = environment(this_object());
}

checkroom() {
  if(query_current_room() == "/wizards/ahma/orc/forest/for03") {
    call_out("wrongroom1", 3);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for17") {
    call_out("wrongroom2", 3);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for18") {
    call_out("wrongroom3", 3);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for31") {
    call_out("wrongroom4", 3);
  }
}

wrongroom1() {
  init_command("ne");
  say("Man arrives from southwest.\n");
  init_command("n");
  say("Man arrives from south.\n");
}

wrongroom2() {
  init_command("e");
  say("Man arrives from west.\n");
}

wrongroom3() {
  init_command("s");
  say("Man arrives from north.\n");
}

wrongroom4() {
  init_command("sw");
  say("Man arrives from northeast.\n");
}