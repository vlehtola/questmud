object target;
int duration;
int effect;
start(object ob, int i) {
  target = ob;
  duration = i;
  effect = target->query_wis()+target->query_skills("iron will");
  if(effect > 100) effect=100;
  shadow(target, 1);
  call_out("end_stun_res", duration);
}

query_stun_resist() {
  return this_object();
}
query_iiwee() {
	return 1;
}


set_stunned(int i, int a) {
  if(random(effect*5) > random(100)) {
  tell_object(target, "Your hardened mind helps you to resists the stun!\n");
  tell_room(environment(target), target->query_name()+"'s hardened mind helps him to resist the stun!\n", ({ target }) );
  return 0;
  }
 target->set_stunned(int i, int a);
}

end_stun_res() {
  tell_object(target, "Your iron will wears off.\n");
  destruct(this_object());
}
