/* Heal */
object caster
/* bonus [0,300] */
get_heal_amount(int bonus) {
  int i;
  /* bonus [50,150] + wis [30,150] = [80,300]*/
  i = bonus/2 + caster->query_wis()/2;
  if(i>350) i = 350;
  /* mastery [0,126] */
  i += i*caster->query_skills("mastery of medicine")/100;
  /* heal tune //Celtron */
  if(!caster->query_npc()) { i += caster->query_mastery()["Knowledge of healing"]/2; }

  caster->reduce_sp((i-100)/4);
  return i;
}

resolve(int bonus, string target, caster_ob) {
   object ob, ob2, enemy;
   string target2;
   int effect;
   if(!caster_ob)caster_ob=caster_ob;
   caster=caster_ob;
   if (!target) {
        ob = caster_ob;
   }
   if (!ob) ob = present(target, environment(caster_ob));
   if (!ob) {
        tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
        return 1;
   }
   if(ob->query_hp() == ob->query_max_hp()) {
     tell_object(caster_ob, "But the target is fully healed.\n");
     return 1;
   }
   if(ob->query_demon()) {
	  tell_object(caster_ob, "The demon growls angrily at you!\n");
	  return 1;
   }

   effect = get_heal_amount(bonus);
   ob->heal_hp(effect);

   target2 = target;
   if (target) { target = capitalize(target); }
   if (target2) { target2 = capitalize(target2); }
   if (ob == caster_ob) {
     target = "yourself";
     target2 = caster_ob->query_objective()+"self";
   }
   tell_object(caster_ob, "You heal " + target + ".\n");
   tell_room(environment(caster_ob), capitalize(caster_ob->query_name())+" heals "+target2+".\n", ({caster_ob, ob}));
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name()) +
        " heals your wounds.\n");
   }
     if(!random(caster_ob->query_mastery()["Knowledge of healing"]+50)) {
     if(!caster_ob->query_npc()) { caster_ob->set_mastery("Knowledge of healing",(caster_ob->query_mastery()["Knowledge of healing"] + 1)); } }

   /* if target is in combat, the enemy of target doesn't like the caster //Celtron */
   enemy = ob->query_attacker();
   if(ob != caster_ob && enemy && enemy->query_npc() &&
     environment(enemy) == environment(caster_ob) &&
     ob->query_party() != caster_ob->query_party()) {
     tell_room(environment(caster_ob), enemy->query_name()+" gets mad at "+caster_ob->query_name()+".\n");
     enemy->attack_object(caster_ob,1);
   }

   return 1;
}
