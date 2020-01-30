
resolve(string target, caster_ob) {
  object ob, ob2;
  string target2;
  int effect, damage_to_self, heal;

  if(!caster_ob)
    caster_ob=this_player();
  if (!target) {
    ob = caster_ob;
  }
  if (!ob)
    ob = present(target, environment(caster_ob));
  if (!ob) {
    tell_object(caster_ob,"No '"+capitalize(target)+"' here.\n");
    return 1;
  }

// Cannot transfer ep to yourself
  if (ob == caster_ob) {
    tell_object(caster_ob,"You cannot force more endurance to yourself.\n");
    return 1;
  }
  effect = caster_ob->query_ep()/2;
  effect += effect+caster_ob->query_skills("abjuration");
  heal = ob->query_max_ep() - ob->query_ep();
  if(heal > effect);
   heal = effect;
 if (ob == caster_ob || caster_ob->query_ep() == 1) {
    return 1;
  }
  damage_to_self = effect;
  if (damage_to_self >= caster_ob->query_ep()) {
    damage_to_self = caster_ob->query_ep() - 1;
    heal = effect;
  }
  caster_ob->reduce_ep(damage_to_self);
  caster_ob->casting_sp_reduce(heal/10);
  ob->query_ep() + (heal);

  target2 = target;
  target = capitalize(target);
  target2 = capitalize(target2);
  if (ob == caster_ob) {
    target = "yourself";
    target2 = caster_ob->query_objective()+"self";
  }
  tell_object(caster_ob,"You force some of your endurance to " + target + ".\n");
  tell_room(environment(caster_ob),capitalize(caster_ob->query_name())+" refreshes "+target2+
  " by forcing "+ caster_ob->query_possessive() +" own endurance.\n",({ ob }));
  if (ob != caster_ob) {
    tell_object(ob, capitalize(caster_ob->query_name()) +
    " makes you more refreshed by forcing "+
    caster_ob->query_possessive()+" endurance to you.\n");
  }
  return 1;
}
