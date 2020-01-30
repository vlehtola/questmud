object liv;
int type, gain, delay;

start(ob, effect, time) {
  liv = ob;
  gain = effect/3;
  delay = time;
  liv->update_stats();
  shadow(liv, 1);
  update_stats();
  call_out("remove_mentale", delay);
}

query_mentale() { return this_object(); }


remove_mentale() {
  tell_object(liv,"You have a strange feeling that your mental state just shrunk a bit.\n");
  liv->update_stats();
  destruct(this_object());
}

update_stats() {
liv->update_stats();
   liv->set_max_ep(liv->query_max_ep() + gain);
}
