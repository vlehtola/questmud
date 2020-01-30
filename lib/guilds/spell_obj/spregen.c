object liv;
int type, gain, delay;

start(ob, effect, time) {
  liv = ob;
  gain = effect;
  delay = time;
  shadow(liv, 1);
  call_out("remove_spregen", delay);
}

query_regeneration() {
  return 1;
}
    
remove_spregen() {
  tell_object(liv,"Your unnatural mana regeneration stops.\n"); 
  destruct(this_object());
}

death() {
  liv->death();
  destruct(this_object());
}

shadow_heart_beat() {
  liv->add_sp(gain);
}
