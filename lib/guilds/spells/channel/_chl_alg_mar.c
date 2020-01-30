// Align spell chl_alg_mar - Jenny 20.12.2003

#define MASTERY_D "/daemons/mastery_d"

resolve(bonus, target, caster_ob) {
  object ob;
  int effect;
  string target2;
  if(!caster_ob)caster_ob=this_player();
  if (!target) {
    tell_object(caster_ob, "This spell needs a target.\n");
    return 1;
  }
  ob = present(target, environment(caster_ob));
  if (!ob) {
    tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
    return 1;
  }

  target2 = target;
  if (target) { target = capitalize(target); }
  if (target2) { target2 = capitalize(target2); }
  tell_object(caster_ob, "You neutralize "+target+"'s alignment.\n");
  tell_room(environment(caster_ob), caster_ob->query_name()+" neutralizes "+target2+"'s alignment.\n", ({caster_ob, ob}));
  if(ob != caster_ob) {
    tell_object(ob, caster_ob->query_name()+" neutralizes your alignment.\n");
  }
  ob->set_al(0);
  return 1;
}
