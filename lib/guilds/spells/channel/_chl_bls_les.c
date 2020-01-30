#define MASTERY_D "/daemons/mastery_d"

resolve(bonus, target, caster_ob) {
   object ob, ob2;
   string target2;
   int effect, duration;
   if(!caster_ob)caster_ob=this_player();
   if (!target) {
        tell_object(caster_ob, "Cast at what?.\n");
        return 1;
   }
   ob = present(target, environment(caster_ob));
   if (!ob) {
        tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
        return 1;
   }
   if (ob->query_unpain()) {
        tell_object(caster_ob, "That would interfere with the existing spell.\n");
        return 1;
   }
   effect = caster_ob->query_skills("cast bless");
   effect +=caster_ob->query_skills("cast lesser");
   effect = effect*2 + caster_ob->query_wis();
   duration = 60*20+6*bonus;

   if (effect > 500) { effect = 500; }
   if (duration > 60*40) { duration = 60*40; }

   effect += MASTERY_D->mastery("Holy faith",caster_ob,ob);
   duration += MASTERY_D->query_mastery("Holy faith",caster_ob)*2;

   ob2 = clone_object("/guilds/spell_obj/hp_bless.c");
   ob2->start(ob, effect, duration);

   target2 = target;
   if (target) { target = capitalize(target); }
   if (target2) { target2 = capitalize(target2); }
   if (ob == caster_ob) {
   target = "yourself";
   target2 = caster_ob->query_objective()+"self";
   }
   tell_object(caster_ob, "You bless "+target+" with more durability.\n");
   tell_room(environment(caster_ob), caster_ob->query_name()+" blesses "+target2+" with more durability.\n", ({ caster_ob, ob }));
   if(ob != caster_ob) {
   tell_object(ob, caster_ob->query_name()+" blesses you with more durability.\n");
}
   return 1;
}
