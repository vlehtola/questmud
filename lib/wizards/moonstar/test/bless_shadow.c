   object target;
int duration;
int effect;
start(ob) {
  target = ob;
  this_player()->set_int(this_player()->query_int()+(100));
  shadow(target, 1);
  call_out("end_mooni_boost", 100);
}

query_mooni_boost() {
  return this_object();
}

end_mooni_boost() {
  tell_object(target, "You feel your brains smaller.\n");
  this_player()->update_stats();
  destruct(this_object());
}
death(arg) {
  effect = 0;
  this_player()->update_stats();
  this_player()->death(arg);
  if(this_object()) destruct(this_object());
  return 1;
}
