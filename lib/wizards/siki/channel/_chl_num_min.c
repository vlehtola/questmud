resolve(effect_bonus, string target, caster_ob) {
  object ob;
  string cap;
  if(!caster_ob)caster_ob=this_player();
  if (!target) { tell_object(caster_ob,"Cure disease needs a target.\n"); }
  ob = present(target, environment(caster_ob));
  if (!ob) {
    tell_object(caster_ob,"No "+capitalize(target)+" here.\n");
    return 1;
  }
  cap = capitalize(target);
  if (!ob->query_disease()) {
    tell_object(caster_ob,capitalize(target)+" has no disease.\n");
    return 1;
  }
  ob->remove_disease();
  tell_object(caster_ob,"You cure "+cap+"'s disease.\n");
  tell_object(ob, caster_ob->query_name() +
	" removes your disease.\n");
  return 1;
}
