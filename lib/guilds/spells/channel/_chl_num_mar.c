resolve(bonus, target, caster_ob) {
   object ob;
   int effect, exp;
   if(!caster_ob)caster_ob=this_player();
   if (!target) { tell_object(caster_ob,"Remove scar from who?\n"); return; }
   ob = find_player(lower_case(target));
   if (!ob || !present(ob,environment(caster_ob))) { tell_object(caster_ob,"No "+capitalize(target)+" here.\n"); return 1; }
   if (!ob->remove_scar()) {
	tell_object(caster_ob,capitalize(target) + " has no scars.\n");
	return 1;
   }
   tell_object(caster_ob,"You remove a scar from "+capitalize(target)+"'s body.\n");
   tell_room(environment(caster_ob),caster_ob->query_name()+" removes a scar from "+capitalize(target)+".\n", ({caster_ob, ob}));
   tell_object(ob, caster_ob->query_name()+" removes a scar from your body.\n");
}
