/* Distant heal */

resolve(bonus, string target, caster_ob) {
  object ob, ob2;
  int effect;
  if(!caster_ob)caster_ob=this_player();
  if (!target) {
    tell_object(caster_ob, "Heal who?\n");
    return 1;
  }
   ob = find_player(target);
   if (!ob || ob->query_link_dead()) {
        tell_object(caster_ob, "You are unable to locate "+capitalize(target)+".\n");
        return 1;
   }
   effect = "/guilds/spells/channel/_chl_hea_min"->get_heal_amount(bonus);
   effect = effect/2;
   ob->heal_hp(effect);

   target = capitalize(target);

   if(ob->query_wiz()) {
     tell_object(caster_ob, "Wizards do not require your aid.\n");
     return 1;
   }
   if (file_name(environment(ob))[0..20] == "/wizards/bulut/event/") {
	tell_object(caster_ob, "Something prevents you from casting the spell.\n");
	return 1;
	}
   if (ob == caster_ob) { target = "yourself"; }
   tell_object(caster_ob, "You distantly heal " + target + ".\n");
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name()) +
        " heals your wounds from a distance.\n");
   }

   return 1;
}
