object target;
int duration;

start(object ob, int i) {
  target = ob;
  duration = i;
  shadow(target, 1);
  call_out("end_stun_res", duration);
}

query_stun_resist() {
  return this_object();
}
query_iiwee() {
	return 1;
}


set_stunned() {
  tell_object(target, "Your hardened mind helps you to resists the stun!\n");
  tell_room(environment(target), target->query_name()+"'s hardened mind helps him to resist the stun!\n", ({ target }) );
  return 0;
}

end_stun_res() {
  tell_object(target, "Your iron will wears off.\n");
  destruct(this_object());
}
