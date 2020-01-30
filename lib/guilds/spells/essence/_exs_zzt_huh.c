resolve(bonus, target, caster_ob) {
  object tp, ob;
  int i,skill;
  string tmp,tmp2;
  tmp = "*********************";
  tmp2 = ".....................";
  tp = caster_ob;
  skill = tp->query_skills("cast information");
  if(!target) {
    tell_object(caster_ob, "Cast at whom?\n");
    return 1;
  }
  ob = present(target, environment(tp));
  if(!ob) {
    tell_object(caster_ob, "No "+target+" here.\n");
    return 1;
  }
  if(!living(ob)) {
    tell_object(caster_ob, ob->short()+" is not a living being.\n");
    return 1;
  }
  tell_object(caster_ob, ob->short()+"\n");
  i = ob->query_level()*2;
  tell_object(caster_ob, "Level: ["+extract(tmp,0,i/5)+extract(tmp2,0,20-i/5)+"]\n");
  i = ob->query_exp() / 10000;
  tell_object(caster_ob, "Exp: ["+extract(tmp,0,i/5)+extract(tmp2,0,20-i/5)+"]\n");
  tell_object(caster_ob, ob->query_pronoun()+" has following protections against elements:\n");
  tell_object(caster_ob, "Fire "+ob->query_resists("fire")+" Cold "+ob->query_resists("cold")+"\n"+
	"Electric "+ob->query_resists("electric")+" Poison "+ob->query_resists("poison")+"\n");

  return 1;
}

