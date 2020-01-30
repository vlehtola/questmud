inherit "obj/monster";
object room;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+22);
  set_name("woman");
  set_alias("walkeri");
  set_race("orc");
  set_gender(2);
  set_short("An Orcish woman is walking on the street");
  set_long("A common-looking Orcish woman is walking on the street. The woman seems\n" + 
           "to be walking just for fun, which can be concluded from her walking speed.\n" + 
           "Woman's lips are painted with light red and her cheeks have been powdered\n" + 
           "with faint pink. Despite the makeup, the woman looks as attractive as the\n" + 
           "other Orcs in the village.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Woman hums somehow familiar melody.\n";
    chat_str[1] = "Woman stares at the sky dreamingly.\n";
    chat_str[2] = "Woman strokes her hair and smiles at you.\n";
  }
  load_chat(3, chat_str);

  if(!present("dress", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/dress"), this_object()); init_command("wear dress"); }
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());
  set_move_at_random(5 + random(15));
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
  say("Woman arrives from southwest.\n");
  init_command("n");
  say("Woman arrives from south.\n");
}

wrongroom2() {
  init_command("e");
  say("Woman arrives from west.\n");
}

wrongroom3() {
  init_command("s");
  say("Woman arrives from north.\n");
}

wrongroom4() {
  init_command("sw");
  say("Woman arrives from northeast.\n");
}