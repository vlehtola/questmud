object spbless_tgt;
int spbless_gain, spbless_delay;

start(ob, effect, time) {
  spbless_tgt = ob;
  spbless_gain = effect;
  spbless_delay = time;
  shadow(spbless_tgt, 1);
  call_out("remove_bunpain", spbless_delay);
  set_max_sp(spbless_tgt->query_max_sp());
}

query_unpain() {
  return 1;
}

remove_bunpain() {
  tell_object(spbless_tgt,"You feel inferior.\n");
  tell_room(environment(spbless_tgt), spbless_tgt->query_name()+" feels inferior.\n", ({ spbless_tgt }));
  spbless_tgt->set_max_sp(spbless_tgt->query_max_sp() - spbless_gain);
  spbless_gain = 0;
  destruct(this_object());
}

death() {
  spbless_tgt->death();
  destruct(this_object());
}

set_max_sp(int i) {
spbless_tgt->set_max_sp(i + spbless_gain);
}