/* Resist stun */

resolve(int bonus, string target, object caster_ob) {
   object ob, resist_ob;
   string target2;
   int duration;
   if(!caster_ob)caster_ob=this_player();
   if (!target) {
	ob = caster_ob;
   }
   if (!ob) ob = present(target, environment(caster_ob));
   if (!ob) {
	tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
	return 1;
   }
   if (ob->query_stun_resist()) {
      tell_object(caster_ob, "There already is a Stun Resistance spell in effect on " +ob->query_name() + "\n");
      return 1;
   }
   duration = bonus * 3;
   resist_ob = clone_object("/guilds/spell_obj/stun_resist_ob");
   resist_ob->start(ob, duration);

   target2 = target;
   if (target) { target = capitalize(target); }
   if (target2) { target2 = capitalize(target2); }
   if (ob == caster_ob) {
     target = "yourself";
     target2 = caster_ob->query_objective()+"self";
   }
   tell_object(caster_ob, "You cast stun resistance at " + target + ".\n");
   tell_room(environment(caster_ob), caster_ob->query_name()+" casts stun resistance at "+ target2+".\n", ({ caster_ob, ob, }));
   if (ob != caster_ob) {
     tell_object(ob, caster_ob->query_name() +" cast stun resistance at you.\n");
   }
   tell_object(ob, "You feel slightly numb as the spell takes effect.\n");

   return 1;
}
