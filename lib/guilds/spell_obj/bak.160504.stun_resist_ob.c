/* STUN RES IS TO BE FAIL SAFE //Celtron */
/* DO NOT CHANGE! */

object stunres_target;
int stunres_duration, stunres_effect;

start(object ob, int i, int power) {
  stunres_target = ob;
  stunres_duration = i;
  shadow(stunres_target, 1);
  call_out("end_stun_res", stunres_duration);
}

query_stun_resist() {
  return this_object();
}

set_stunned(num, i) {
  tell_object(stunres_target, "You resist the stun!\n");
  tell_room(environment(stunres_target), stunres_target->query_name()+" resists the stun!\n", ({ stunres_target }) );
  return 0;
}

end_stun_res() {
  tell_object(stunres_target, "Your stun resistance wears off.\n");
  destruct(this_object());
}
