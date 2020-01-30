object player;
int time,reflect,extra;

start(object ob,int bonus) {
  player = ob;
  extra = bonus/25;
  time = bonus;
  call_out("end_antireflect",time);
  shadow(player, 1);
  tell_object(player, "You are surrounded by antireflecting shield.\n");
}

end_antireflect() {
  tell_object(player, "The antireflecting shield around you dissipates.\n");
  destruct(this_object());
}

query_antireflect_bonus() { return extra; }
