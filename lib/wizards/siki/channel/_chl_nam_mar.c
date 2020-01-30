/* Satisfy hunger/thirst */

resolve(int bonus, string target, caster_ob) {
   object ob, ob2;
   string target2;
   if(!caster_ob)caster_ob=this_player();
   if (!target) {
        ob = caster_ob;
   }
   if (!ob) ob = present(target, environment(caster_ob));
   if (!ob) {
        tell_object(caster_ob,"No '"+capitalize(target)+"' here.\n");
        return 1;
   }
   target2 = target;
   if (target) { target = capitalize(target); }
   if (target2) { target2 = capitalize(target2); }
   if (ob == caster_ob) {
     target = "yourself";
     target2 = caster_ob->query_objective()+"self";
   }
   tell_object(caster_ob,"You satisfy " + target + ".\n");
   tell_room(environment(caster_ob), capitalize(caster_ob->query_name())+" satisfies "+target2+".\n",({caster_ob, ob}));
   ob->eat_food(1000000);
   ob->drink_soft(100000);
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name()) +
        " satisfies your hunger and thirst.\n");
   return 1;
   }
}
