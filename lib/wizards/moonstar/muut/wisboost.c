   object target;
int duration;
int effect;
start(object ob, int i) {
  target = ob;
  duration = i;
  effect = 100;
  this_player()->set_wis(this_player()->query_wis()+(100));
  shadow(target, 1);
  call_out("end_wis_boost", duration);
}

query_wis_boost() {
  return this_object();
}
query_wisboost() {
        return 1;
}

end_wis_boost() {
  tell_object(target, "You feel like losing some of your wisdom.\n");
  destruct(this_object());
}

