// Sex change to he chl_sex_les - Jenny 2.2.2004

#define MASTERY_D "/daemons/mastery_d"

resolve(int bonus, string target, object caster_ob) {
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

    if(ob->query_wiz()) {
        tell_object(caster_ob, "You should have known better FOOL!\n");
        caster_ob->reduce_hp(caster_ob->query_hp()-1);
        return 1;
    }

  ob->set_gender(1);
  target2 = target;
  if (target) { target = capitalize(target); }
  if (target2) { target2 = capitalize(target2); }
  if (ob == caster_ob) {
    target = "yourself";
    target2 = caster_ob->query_objective()+"self";
  }
  tell_object(caster_ob, "You change "+target+"'s gender\n");
  tell_room(environment(caster_ob), caster_ob->query_name()+" changes gender from "+target2+".\n", ({caster_ob, ob}));
  if(ob != caster_ob) {
    tell_object(ob, caster_ob->query_name()+" changes your gender\n");
  }
  return 1;
}
