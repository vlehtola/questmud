resolve(bonus, string target, caster_ob) {
   object ob, ob2;
   string target2;
   int effect;
   if(!caster_ob)caster_ob=this_player();
   if (!target) {
	ob = caster_ob;
   }
   if (!ob) ob = present(target, environment(caster_ob));
   if (!ob) {
	tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
	return 1;
   }
   if(ob->query_attacker()) {
     tell_object(caster_ob, "You are unable to true heal anyone who's in combat.\n");
     return 1;
   }
   if(ob->query_demon()) {
	  tell_object(caster_ob, "The demon growls angrily at you!\n");
	  return 1;
  }
   effect = ob->query_max_hp() - ob->query_hp();

   ob->heal_hp(effect);

   effect -= effect * this_player()->query_skills("mastery of medicine") / 200;
   /* heal tune. lievempi kun perushealissa. //Celtron */
   caster_ob->reduce_sp(effect/6);

   target2 = target;
   if (stringp(target)) target = capitalize(target);
   if (stringp(target2)) target2 = capitalize(target2);
   if (ob == caster_ob) {
     target = "yourself";
     target2 = caster_ob->query_objective()+"self";
   }
        if(!random(caster_ob->query_mastery()["Knowledge of healing"]+50)) {
        if(!caster_ob->query_npc()) { caster_ob->set_mastery("Knowledge of healing",(caster_ob->query_mastery()["Knowledge of healing"] + 1)); } }
   tell_object(caster_ob, "You cast True Heal at " + target + ".\n");
   tell_room(environment(caster_ob), capitalize(caster_ob->query_name())+" casts True Heal at "+target2+".\n", ({caster_ob, ob}));
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name()) +" completely heals your wounds.\n");
   }

   return 1;
}
