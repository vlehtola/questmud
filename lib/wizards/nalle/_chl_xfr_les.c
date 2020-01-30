resolve(int bonus, string target, caster_ob) {
   object ob, ob2;
   string target2;
   int effect, damage_to_self, heal;
   if(!caster_ob)caster_ob=this_player();
   if (!target) {
	ob = caster_ob;
   }
   if (!ob) ob = present(target, environment(caster_ob));
   if (!ob) {
	tell_object(caster_ob,"No '"+capitalize(target)+"' here.\n");
	return 1;
   }

//fixed by Celtron
  "/guilds/spells/channel/_chl_hea_min"->get_heal_amount(bonus,caster_ob);

/* Transferring ja healing ero: */
   effect = effect * 5;
   effect += effect*caster_ob->query_skills("mastery of medicine") /(80*5);

   heal = ob->query_max_hp() - ob->query_hp();
   if(heal > effect) heal = effect;

   if (ob == caster_ob || caster_ob->query_hp() == 1) { return 1; }
   damage_to_self = heal/3;
   if (damage_to_self >= caster_ob->query_hp()) {
     damage_to_self = caster_ob->query_hp() - 1;
     heal = damage_to_self * 3;
   }
   caster_ob->reduce_hp(damage_to_self);
   caster_ob->casting_sp_reduce(heal/10);
   ob->heal_hp(heal);

   target2 = target;
   target = capitalize(target);
   target2 = capitalize(target2);
   if (ob == caster_ob) {
     target = "yourself";
     target2 = caster_ob->query_objective()+"self";
   }
   tell_object(caster_ob,"You transfer some of your health to " + target + ".\n");
   tell_room(environment(caster_ob),capitalize(caster_ob->query_name())+" heals "+target2+
" by transferring his own health.\n",ob);
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name()) +
	" heals your wounds by transferring "+
	caster_ob->query_possessive()+" health to you.\n");
   }

   return 1;
}
