// Beauty Fixes by gynt'man
// And fixed by Jenny after Gynter...
#define MASTERY_D "/daemons/mastery_d"

resolve(bonus, string target, caster_ob) {
/* Declarations */
  object ob, ob2;
  string target2;
  int effect,heal_to_self;

/* Code */
  if(!caster_ob)
    caster_ob=this_player();
  if (!target) {
    ob = caster_ob;
    target = ob->query_name();
  } else
    target = lower_case(target);
  if (!ob)
    ob = present(target, environment(caster_ob));
  if(!ob || !living(ob) || ob == caster_ob) {
    tell_object(caster_ob,capitalize(target)+" is not a valid target.\n");
    return 1;
  }
  effect = caster_ob->query_wis()*2 + 20;
  effect = effect * caster_ob->query_skills("cast transfer") / 70;

  if(effect > 50)
    effect = 50 + (effect-50)/2;
  if(effect > 150)
    effect = 150 + (effect-150)/2;
  if(effect > 200)
    effect = 200;

   effect += MASTERY_D->mastery("Holy faith",caster_ob,ob)/2;

  heal_to_self = effect/2;
  if (effect/2 >= ob->query_hp()) {
     heal_to_self = caster_ob->query_hp() - 1;
//added max to healself --Jenny
  if(heal_to_self > 150)
  heal_to_self = 150;

  }
  target2 = target;
  target = capitalize(target);
  target2 = capitalize(target2);
  if (ob == caster_ob) {
    target = "yourself";
    target2 = caster_ob->query_objective()+"self";
  }

  if(ob->query_heal_resist()) {
    tell_object(caster_ob,target+" resists the drain!\n");
    tell_object(ob, "You resist the drain!\n");
    return 1;
  }
  tell_object(caster_ob,"You drain some of " + target + "'s health to yourself.\n");
  tell_room(environment(caster_ob),caster_ob->query_name()+" drains some of "+target+"'s health to "+caster_ob->query_objective()+"self.\n", ({caster_ob, ob}));
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name())+" drains some of your health to "+caster_ob->query_objective()+"self.\n");
   }
   caster_ob->attack_object(ob,1);
// effect = ob->hit_with_spell(effect,"physical",caster_ob);
// Tuned to ignore resists -- Rag 3.6.04
   caster_ob->add_party_exp(random(effect)*10);
   ob->reduce_hp(effect);
// Removed divider by 4 by Gynter
   caster_ob->heal_hp(heal_to_self);
   return 1;
}
