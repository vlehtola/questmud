#define STACK_MAX 3
#define EFFECT_MAX 70

object backfire_tgt;
int stack, backfire_effect;

add_stack(object ob, int duration, int i) {
  if(stack >= STACK_MAX) {
    return 0;
  }
  if(!backfire_tgt) {
    backfire_tgt = ob;
    shadow(backfire_tgt, 1);
  }
  backfire_effect += i;
  if(backfire_effect > EFFECT_MAX) backfire_effect = EFFECT_MAX;
  stack += 1;
  tell_room(environment(backfire_tgt) , "The violet aura suddenly starts to glow brighter.\n");
  call_out("end_backfire", duration);
}

hit_player(int damage, mixed pref, object ob, arg2, arg3) {
  int backfire;
  /* backfire_effect [0, 70] */
  if(random(200)+1 > backfire_effect+100 && ob) {
    tell_room(environment(backfire_tgt), "The violet aura flashes.\n");
    backfire = damage * backfire_effect / 100;
    ob->hit_with_spell(backfire, pref, 0, arg2, arg3);
  }
  return backfire_tgt->hit_player(damage, pref, ob, arg2, arg3);
}

hit_with_spell(int damage, mixed pref, object ob, arg2, arg3) {
  int backfire;
  /* backfire_effect [0, 70] */
  if(random(200)+1 > backfire_effect+100 && ob) {
    tell_room(environment(backfire_tgt), "The violet aura flashes.\n");
    backfire = damage * backfire_effect / 100;
    ob->hit_with_spell(backfire, pref, 0, arg2, arg3);
  }
  return backfire_tgt->hit_with_spell(damage, pref, ob, arg2, arg3);
}

short(arg, arg2) {
  if(arg) return backfire_tgt->short(arg,arg2);
  return backfire_tgt->short(arg,arg2)+" {violet aura}";
}

end_backfire() {
  backfire_effect -= backfire_effect / stack;
  stack -= 1;
  if(stack == 0) {
    tell_object(backfire_tgt, "The violet aura surrounding you fades away.\n");
    destruct(this_object());
  }
  tell_object(backfire_tgt, "The violet aura surrounding you gets dimmer.\n");
}

query_backfire() {
  return this_object();
}
