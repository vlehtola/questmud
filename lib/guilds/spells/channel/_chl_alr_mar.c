/* backfire */

#define MASTERY_D "/daemons/mastery_d"

resolve(int bonus, string target, object caster_ob) {
   object ob, spell_ob;
   string target2;
   int duration, effect, new;
   if(!caster_ob)caster_ob=this_player();
   if (!target) {
        ob = caster_ob;
   }
   if (!ob) ob = present(target, environment(caster_ob));
   if (!ob) {
        tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
        return 1;
   }
   duration = bonus * 2 + random(bonus);
   effect = 10 + (bonus / 20);

   effect += MASTERY_D->mastery("Holy faith",caster_ob,ob)/5;
   duration += MASTERY_D->query_mastery("Holy faith",caster_ob)*2;

   spell_ob = ob->query_backfire();
   if (!spell_ob) {
     spell_ob = clone_object("/guilds/spell_obj/backfire_ob");
     new = 1; /* Flagi teksteja varten, ei muuta */
   }
   spell_ob->add_stack(ob, duration, effect);

   target2 = target;
   if (target) { target = capitalize(target); }
   if (target2) { target2 = capitalize(target2); }
   if (ob == caster_ob) {
     target = "yourself";
     target2 = ob->query_pronoun();
   }
   if (!new) {
     tell_object(caster_ob, "You grant " + target + " a Backfire enchantment.\n");
   } else {
     tell_object(caster_ob, "You enhance the Backfire enchantment on "+target+".\n");
   }
   tell_room(environment(caster_ob), caster_ob->query_name()+" completes a spell and "+target2+" starts glowing.\n", ({ caster_ob, ob,}));
   if (ob != caster_ob) {
     tell_object(ob, caster_ob->query_name()+" casts a Backfire enchantment on you.\n");
   }

   return 1;
}
