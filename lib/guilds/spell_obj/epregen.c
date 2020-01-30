object liv;
int type, gain, delay;

start(ob, effect, time) {
  liv = ob;
  gain = effect;
  delay = time;
  shadow(liv, 1);
  call_out("remove_epregen", delay);
}

query_regeneration() {
  return 1;
}
    
remove_epregen() {
  tell_object(liv,"Your unnatural endurance regeneration stops.\n");
  destruct(this_object());
}

death() {
  liv->death();
  destruct(this_object());
}

shadow_heart_beat() {
  liv->add_ep(gain);
}
