inherit "obj/monster";
int i = random(8), h;
object room;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+10);
  set_name("child");
  set_alias("walkeri");
  set_race("orc");
  if(i==0) { set_short("A lively child"); }
  if(i==1) { set_short("A running child"); }
  if(i==2) { set_short("A smiling little kid"); }
  if(i==3) { set_short("A red-haired boy"); }
  if(i==4) { set_short("A bossy little boy"); }
  if(i==5) { set_short("A little girl with pink cheeks"); }
  if(i==6) { set_short("A young girl is running here"); }
  if(i==7) { set_short("A girl is trying to find her mother"); }

  if(i==0 || i==1 || i==2 || i==3 || i==4) { set_alt_name("boy"); set_gender(1);
  set_long("A young Orcish boy seems to enjoy his childhood. This small, green figure\n" + 
           "has somewhat reddish cheeks and little drops of sweat run down on his\n" + 
           "forehead and temples which are partly covered with dirty hair. The child\n" + 
           "seems to be constantly on the move, which is not a peculiar sight among\n" +
           "among the kids in this village.\n");
  }
  if(i==5 || i==6 || i==7) { set_alt_name("girl"); set_gender(2);
  set_long("A young Orcish girl seems to enjoy her childhood. This small, green figure\n" + 
           "is wearing a small pink dress. She has somewhat reddish cheeks and she\n" + 
           "seems to breath quite frequently. The girl seems to be constantly on the\n" + 
           "move, which is not a peculiar sight among the children in this village.\n");
  }

  if(!chat_str) {
    chat_str = allocate(4);
    chat_str[0] = "Child snickers insanely.\n";
    chat_str[1] = "Child examines you full of interest.\n";
    chat_str[2] = "Child yells happily.\n";
    if(i==0) { chat_str[3] = "Child crawls and rolls on the ground.\n"; }
    if(i==1) { chat_str[3] = "Child's hair flutter in the air as he runs around.\n"; }
    if(i==2) { chat_str[3] = "Kid smiles friendly at you.\n"; }
    if(i==3) { chat_str[3] = "Boy pokes you in the ribs and runs away.\n"; }
    if(i==4) { chat_str[3] = "Boy shouts at you: 'Hey! Where do you think you're going?!'\n"; }
    if(i==5) { chat_str[3] = "Girl curtseys at you and smiles.\n"; }
    if(i==6) { chat_str[3] = "Girl's braids bounce around as she runs.\n"; }
    if(i==7) { chat_str[3] = "Girl sobs: 'Where did my mom go?'\n"; }
    
  }
  load_chat(3, chat_str);
  
  if(i==5 || i==6 || i==7) {
    if(!present("dress", this_object())) { move_object(clone_object("/wizards/ahma/orc/eq/dress"), this_object()); init_command("wear dress"); }
  }
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
  say("Child arrives from southwest.\n");
  init_command("n");
  say("Child arrives from south.\n");
}

wrongroom2() {
  init_command("e");
  say("Child arrives from west.\n");
}

wrongroom3() {
  init_command("s");
  say("Child arrives from north.\n");
}

wrongroom4() {
  init_command("sw");
  say("Child arrives from northeast.\n");
}
