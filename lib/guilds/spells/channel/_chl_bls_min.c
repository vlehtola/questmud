// Beauty fixes by Gynter

#define MASTERY_D "/daemons/mastery_d"

resolve(bonus, target, caster_ob) {
  object ob, ob2;
  int effect, duration;
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
  if (ob->query_regeneration()) {
    tell_object(caster_ob, "That would interfere with the existing spell.\n");
    return 1;
  }
  effect = caster_ob->query_skills("cast bless");
  effect +=caster_ob->query_skills("cast minor");
  effect += caster_ob->query_wis()/2;
  effect = effect / 15;
  duration = 5*60+bonus;

  if (effect > 10) { effect = 10; }
  if (duration > 600) { duration = 600; }

  effect += (MASTERY_D->mastery("Holy faith",caster_ob,ob)+10)/10;
  duration += MASTERY_D->query_mastery("Holy faith",caster_ob);


  ob2 = clone_object("/guilds/spell_obj/hpregen.c");
  ob2->start(ob, effect, duration);
  target2 = target;
  if (target) { target = capitalize(target); }
  if (target2) { target2 = capitalize(target2); }
  if (ob == caster_ob) {
    target = "yourself";
    target2 = caster_ob->query_objective()+"self";
  }
  tell_object(caster_ob, "You cast regeneration on "+target+".\n");
  tell_room(environment(caster_ob), caster_ob->query_name()+" cast a regeneration spell on "+target2+".\n", ({caster_ob, ob}));
  if(ob != caster_ob) {
    tell_object(ob, caster_ob->query_name()+" casts a regeneration spell on you.\n");
  }
  return 1;
}
