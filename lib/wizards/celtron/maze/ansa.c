int ready;

init() {
  if(this_player()->is_npc()) return;
  if(ready) {
    zap(this_player());
  } else {
    say("You hear a humming sound nearby.\n");
    call_out("zap", 30, this_player());
  }
}

zap(ob) {
  ready = 1;
  if(!ob) ob = this_player();
  if(present(ob,environment(this_object()))) return;
  write("You feel an enormous shock waving through your nerves!\n");
  say(ob->query_name() +" is struck by an electric shock!\n");
  ob->hit_with_spell(150+random(200), 5);
  call_out("zap", 30, ob);
  return 1;
}


