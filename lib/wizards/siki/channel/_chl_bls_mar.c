resolve(bonus, target, caster_ob) {
   object ob, ob2;
   string target2;
   int effect, duration;
   if(!caster_ob)caster_ob=this_player();
   if (!target) {
	tell_object(caster_ob, "Cast at whom?\n");
	return 1;
   }
   ob = present(target, environment(this_player()));
   if (!ob) {
	tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
	return 1;
   }
   if (ob->query_unpain()) {
        tell_object(caster_ob, "That would interfere with the existing spell.\n");
        return 1;
   }

   effect = caster_ob->query_skills("cast bless");
   effect += caster_ob->query_skills("cast major");
   effect = effect*2 + caster_ob->query_wis();
   duration = 20*60+5*bonus;

   if (effect > 500) { effect = 500; }
   if (duration > 40*60) { duration = 40*60; }

   ob2 = clone_object("/guilds/spell_obj/bunpain.c");
   ob2->start(ob, effect, duration);
   target2 = target;
   if (target) { target = capitalize(target); }
   if (target2) { target2 = capitalize(target2); }
   if (ob == caster_ob) {
   target = "yourself";
   target2 = caster_ob->query_objective()+"self";
   }

  tell_object(caster_ob, "You bless "+target+" with more mana.\n");
  tell_room(environment(caster_ob),caster_ob->query_name()+" blesses "+target2+" with more mana.\n", ({ caster_ob, ob }));
   if(ob != caster_ob) {
   tell_object(ob, this_player()->query_name()+" blesses you with more mana.\n");
}
   return 1;
}
