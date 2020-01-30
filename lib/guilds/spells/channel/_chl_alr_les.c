/* Resist heal */

#define MASTERY_D "/daemons/mastery_d"

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
        write("No '"+capitalize(target)+"' here.\n");
        return 1;
   }
   if (ob->query_heal_resist()) {
      tell_object(caster_ob, "There already is a Heal Resistance spell in effect on " +ob->query_name()+ "\n");
      return 1;
   }
   duration = bonus;
   duration += MASTERY_D->mastery("Holy faith",caster_ob,ob);

   resist_ob = clone_object("/guilds/spell_obj/heal_resist_ob");
   resist_ob->start(ob, duration, caster_ob);


   target2 = target;
   if (target) { target = capitalize(target); }
   if (target2) { target2 = capitalize(target2); }
   if (ob == caster_ob) {
     target = "yourself";
     target2 = caster_ob->query_objective()+"self";
   }
   tell_object(caster_ob, "You cast heal resistance at " + target + ".\n");
   tell_room(environment(caster_ob), caster_ob->query_name()+" casts heal resistance at "+
        target2+".\n",({ ob, caster_ob, }));
   if (ob != caster_ob) {
     tell_object(ob, caster_ob->query_name() +
        " cast heal resistance at you.\n");
   }
   tell_object(ob, "Your flesh suddenly wont heal anymore.\n");

   return 1;
}
