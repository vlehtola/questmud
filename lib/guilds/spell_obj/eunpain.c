object liv;
int type, gain, delay;

start(ob, effect, time) {
  liv = ob;
  gain = effect;
  delay = time;
  shadow(liv, 1);
  call_out("remove_eunpain", delay);
  update_hp();
}

query_unpain() {
  return 1;
}
    
remove_eunpain() {
  tell_object(liv,"You feel strangely exhausted.\n");
  destruct(this_object());
}

death() {
  liv->death();
  destruct(this_object());
}

update_hp() {
  liv->update_hp();
  liv->set_max_ep(liv->query_max_ep() + gain);
}
