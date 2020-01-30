
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
  effect = effect * caster_ob->query_skills("cast force") / 70;

  if(effect > 150)
    effect = 150 + (effect-50)/2;
  if(effect > 250)
    effect = 250 + (effect-150)/2;
  if(effect > 400)
    effect = 400;

   effect += MASTERY_D->mastery("mastery of shielding",caster_ob,ob)/3;

  heal_to_self = effect/2;
  if (effect/2 >= ob->query_sp()) {
     heal_to_self = caster_ob->query_sp() - 1;
  }
  target2 = target;
  target = capitalize(target);
  target2 = capitalize(target2);
  if (ob == caster_ob) {
    target = "yourself";
    target2 = caster_ob->query_objective()+"self";
  }
  tell_object(caster_ob,"You force some of " + target + "'s mana to yourself.\n");
  tell_room(environment(caster_ob),caster_ob->query_name()+" forces some of "+target+"'s mana to "+caster_ob->query_objective()+"self.\n", ({caster_ob, ob}));
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name())+" forces some of your mana to "+caster_ob->query_objective()+"self.\n");
   }
   caster_ob->attack_object(ob,1);
   effect = (ob->query_sp() - effect);
   caster_ob->query_sp() + (heal_to_self);
   return 1;
}
