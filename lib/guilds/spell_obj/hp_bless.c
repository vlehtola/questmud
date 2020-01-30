object hpbless_tgt;
int hpblessgain, hpblessdelay;

start(ob, effect, time) {
  hpbless_tgt = ob;
  hpblessgain = effect;
  hpblessdelay = time;
  shadow(hpbless_tgt, 1);
  call_out("remove_unpain", hpblessdelay);
  set_max_hp(hpbless_tgt->query_max_hp());
  hpbless_tgt->heal_hp(1);
}

query_unpain() {
  return 1;
}

remove_unpain() {
  if(hpbless_tgt) {
  tell_object(hpbless_tgt,"You feel weaker.\n");
  tell_room(environment(hpbless_tgt), hpbless_tgt->query_name()+" seems a lot weaker.\n", ({ hpbless_tgt }));
  }
  hpbless_tgt->set_max_hp(hpbless_tgt->query_max_hp() - hpblessgain);
  hpbless_tgt->heal_hp(1);
  hpblessgain = 0;
  destruct(this_object());
}

death() {
  hpbless_tgt->set_max_hp(hpbless_tgt->query_max_hp() - hpblessgain);
  hpbless_tgt->death();
  destruct(this_object());
}

set_max_hp(int i) {
hpbless_tgt->set_max_hp(i + hpblessgain);
}
