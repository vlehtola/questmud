// Align spell chl_alg_mar - Jenny 20.12.2003

#define MASTERY_D "/daemons/mastery_d"

resolve(target, caster_ob) {
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
  effect = this_player()->set_al(0);

  target2 = target;
  if (target) { target = capitalize(target); }
  if (target2) { target2 = capitalize(target2); }
  if (ob == caster_ob) {
    target = "yourself";
    target2 = caster_ob->query_objective()+"self";
  }
  tell_object(caster_ob, "You neutralize "+target+" alignment.\n");
  tell_room(environment(caster_ob), caster_ob->query_name()+" neutralizes alignment from "+target2+".\n", ({caster_ob, ob}));
  if(ob != caster_ob) {
    tell_object(ob, caster_ob->query_name()+" neutralizes your alignment.\n");
  }
  return 1;
}
