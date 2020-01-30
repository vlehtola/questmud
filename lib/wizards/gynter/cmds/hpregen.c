object hpreg_tgt;
int hpreg_gain, hpreg_delay;

start(ob, effect, time) {
  hpreg_tgt = ob;
  hpreg_gain = effect;
  hpreg_delay = time;
  shadow(hpreg_tgt, 1);
  call_out("remove_hpregen", hpreg_delay);
}

query_regeneration() {
  return 1;
}

remove_hpregen() {
  tell_object(hpreg_tgt,"Your unnatural regeneration stops.\n");
  destruct(this_object());
}

death() {
  hpreg_tgt->death();
  destruct(this_object());
}

shadow_heart_beat() {
if(!hpreg_tgt->query_attack()) {
  hpreg_tgt->add_hp(hpreg_gain);
}
}
