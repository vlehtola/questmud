/* STUN RES IS TO BE FAIL SAFE //Celtron */
/* DO NOT CHANGE! */
// Changed it to wear off after one resist. It is still fail safe.
// -N (backup in bak.160504.stun_resist_ob.c)


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
  //end_stun_res(); // -N 160504
  return 0;
}

end_stun_res() {
  tell_object(stunres_target, "Your stun resistance wears off.\n");
  destruct(this_object());
}
