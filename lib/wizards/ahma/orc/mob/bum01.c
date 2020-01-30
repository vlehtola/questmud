inherit "obj/monster";
object plr;
string who, what;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 15);
  set_name("bum");
  set_alias("man");
  set_short("A starving Orcish bum");
  set_gender(1);
  set_race("orc");
  set_long("This withered and skinny man looks very sick. Man's ribs can be seen\n" + 
           "through his thin layer of skin as he sits in the corner of the room and\n" + 
           "mumbles something to himself. The pain of this man can almost be felt\n" + 
           "when standing near enough of him. His eyes are full of sorrow.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Bum sobs quietly.\n";
    chat_str[1] = "Bum raises his head and looks at you with his wet eyes.\n";
    if(!h) { chat_str[2] = "Bum says: 'Please, bring me some food.. Sir.'\n"; }
    else { chat_str[2] = "Bum says: 'Oh, at least I'm not hungry anymore.'\n"; }
  }
  load_chat(3, chat_str);
  set_al(30);
}


catch_tell(str) {
  string tmp;
  if(sscanf(str, "%s gives %s to %s", who, what, tmp) == 3) {
  if(what == "A juicy apple" || what == "A handful of red berries" || what == "A piece of white bread" || what == "A chunk of ham" || what == "A piece of old cheese") {
  if(!h) {
    h++;
    plr = find_player(lower_case(who));
    say("Bum bows at " + who + ".\n");
    say("Bum says: 'Thank you so much! I will never forget about your generosity.'\n");
    plr->add_exp(100000 + random(50001));
    environment(this_object())->task_complete();
    task_complete();
  }
  else {
    say("Bum says: 'Thanks, but I'm not hungry any more.'\n");
  }
}
}
}

task_complete() {
  h = 1;
}
