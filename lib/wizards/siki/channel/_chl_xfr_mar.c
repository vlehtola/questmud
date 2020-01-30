resolve(bonus, string target, caster_ob) {
  object ob, ob2;
  string target2;
  int effect, max_dam, dam, sp;
  if(!caster_ob)caster_ob=this_player();
  if (!target) {
    ob = caster_ob;
  }
  if (!ob) ob = present(target, environment(caster_ob));
  if (!ob) {
    tell_object(caster_ob,"No '"+capitalize(target)+"' here.\n");
    return 1;
  }
  if (ob == caster_ob) { tell_object(caster_ob,"You cannot target yourself.\n"); return 1; }
  if(ob->query_hp() < ob->query_max_hp()/2) {
    tell_object(caster_ob,ob->query_name()+" is already harmed.\n");
    return 1;
  }
  /* effect = [0,300] + [0,n] = [0,500] */
  effect = caster_ob->query_skills("cast major") + caster_ob->query_skills("cast transfer") +
		caster_ob->query_skills("cast divine");
  effect += caster_ob->query_wis();
  if(effect > 500) effect = 500;

  max_dam = ob->query_hp() *4/10;
  sp = caster_ob->query_sp();
  dam = sp*effect/25; /* max 1 sp = 20 dam */
  if(dam > max_dam) {
    dam = max_dam;
    sp -= (dam-max_dam)*25/effect;
  }
  if(caster_ob->query_tester())
    tell_object(caster_ob,"Damage: "+dam+" Spcost: "+sp+"\n");
  caster_ob->attack_object(ob,1);
  if(ob->query_heal_resist())
    tell_object(caster_ob,"The target is resistant to healing and harming!\n");
  else
    ob->hit_with_spell(dam,0,caster_ob);
  caster_ob->reduce_sp(sp);

  target2 = target;
  target = capitalize(target);
  target2 = capitalize(target2);
  if (ob == caster_ob) { target = "yourself"; target2 = "himself"; }
  tell_object(caster_ob,"You harm " + target + ".\n");
  tell_room(environment(caster_ob),capitalize(caster_ob->query_name())+" harms "+target+"\n",ob);
  if (ob != caster_ob) {
    tell_object(ob, capitalize(caster_ob->query_name())+" harms you!\n");
  }
  return 1;
}
