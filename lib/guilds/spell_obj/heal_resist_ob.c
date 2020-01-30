object healres_tgt, caster;
int healres_time;

start(object ob, int i, object cast) {
  healres_tgt = ob;
  healres_time = i;
  caster = cast;
  shadow(healres_tgt, 1);
  call_out("end_heal_res", healres_time);
}

heal_hp() {
  tell_object(healres_tgt, "You resist the heal!\n");
  tell_room(environment(healres_tgt), healres_tgt->query_name()+" resists the heal!\n", ({ healres_tgt }) );
  return 0;
}

end_heal_res() {
  tell_object(healres_tgt, "Your heal resistance wears off.\n");
  if(caster) {
    tell_object(caster, "You feel that "+healres_tgt->query_name()+" can be healed again.\n");
  }
  destruct(this_object());
}

query_heal_resist() {
  return this_object();
}

/* called by monster.c */
query_resist_heal() {
  return 1;
}
