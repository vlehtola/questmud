resolve(bonus, target, caster_ob) {
   object ob;
   int effect, exp;
   if(!caster_ob)caster_ob=this_player();
   if (!target) { tell_object(caster_ob,"Remove poison from who?\n"); return; }
   ob = find_player(lower_case(target));
   if (!ob || !present(ob,environment(caster_ob))) { tell_object(caster_ob,"No "+capitalize(target)+" here.\n"); return 1; }
   if (!present("poison_object", ob)) {
	tell_object(caster_ob,ob->query_name()+" is not poisoned.\n");
	return 1;
   }
   present("poison_object", ob)->stop();
   tell_object(caster_ob,"You remove poison from "+capitalize(target)+"'s body.\n");
   tell_room(environment(caster_ob),caster_ob->query_name()+" removes poison from "+capitalize(target)+".\n",ob);
   tell_object(ob, caster_ob->query_name()+" removes poison from your body.\n");
}
