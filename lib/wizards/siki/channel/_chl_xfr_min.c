resolve(bonus, string target, caster_ob) {
  object ob, ob2;
  string target2;
  int effect,heal_to_self;
  if(!caster_ob)caster_ob=this_player();
  if (!target) {
	ob = caster_ob;
	target = ob->query_name();
  }
  else target = lower_case(target);
  if (!ob) ob = present(target, environment(caster_ob));
  if(!ob || !living(ob) || ob == caster_ob) {
        tell_object(caster_ob,capitalize(target)+" is not a valid target.\n");
	return 1;
  }
  effect = caster_ob->query_wis()*2 + 20;
  effect = effect * caster_ob->query_skills("cast transfer") / 70;
  if(!caster_ob->query_npc()) { effect += caster_ob->query_mastery()["Knowledge of draining"]/2; }
  if(effect > 50) effect = 50 + (effect-50)/2;
  if(effect > 150) effect = 150 + (effect-150)/2;
  if(effect > 200) effect = 200;
  heal_to_self = effect/2;
  if (effect/2 >= ob->query_hp()) {
     heal_to_self = caster_ob->query_hp() - 1;
  }
  target2 = target;
  target = capitalize(target);
  target2 = capitalize(target2);
  if (ob == caster_ob) { target = "yourself"; target2 = "himself"; }

  if(ob->query_heal_resist()) {
    tell_object(caster_ob,target+" resists the drain!\n");
    tell_object(ob, "You resist the drain!\n");
    return 1;
  }
  if(!random(caster_ob->query_mastery()["Knowledge of draining"]+50)) {
  if(!caster_ob->query_npc()) { caster_ob->set_mastery("Knowledge of draining",(caster_ob->query_mastery()["Knowledge of draining"] + 1)); } }

  tell_object(caster_ob,"You drain some of " + target + "'s health to yourself.\n");
  tell_room(environment(caster_ob),caster_ob->query_name()+" drains some of "+
	target+"'s health to "+
caster_ob->query_objective()+"self.\n", ob);
   if (ob != caster_ob) {
     tell_object(ob, capitalize(caster_ob->query_name())+" drains "+
	"some of your health to "+
	caster_ob->query_objective()+"self.\n");
   }
   caster_ob->attack_object(ob,1);
   effect = ob->hit_with_spell(effect,"physical",caster_ob);
   caster_ob->heal_hp(heal_to_self/4);
   return 1;
}
