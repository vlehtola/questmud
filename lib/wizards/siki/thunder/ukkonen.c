int i;

start_thunder() {
write("Thunder started\n");
call_out("zap", 60);
i = 1;
}

zap() {
  object list;
  int i,ii;
  list = users();
  i = random(sizeof(list));
  while(list[i]->query_wiz() && ii < 10) {
    i = random(sizeof(list));
    ii += 1;
  }
  zap_ob(list[i]);
  call_out("zap", random(60) + 60);
}

zap_ob(ob) {
  int i;
  i = random(ob->query_hp())+ob->query_hp()/20;
  shout("You hear a loud clap of thunder.\n");
  tell_object(ob, "A lightning strikes at YOU!\n");
  ob->reduce_hp(i);
  if(!ob->query_ghost()) {
    ob->add_exp(i*100);
    if(ob->idle() < 30) ob->add_exp(i*200);
    if(ob->query_attack()) ob->add_exp(i*700);
    tell_object(ob, "Wow, what an experience!\n");
  }
  return 1;
}

end_thunder() {
int i;
i = remove_call_out("zap");
}
