
get_time() {
  return random(2)+4;
}
query_type() { return "offensive"; }
ep_cost() { return 7; }

resolve_skill(str, object ob) {
    int dama, weapon_skill;
    object wepa,limb,target;
    string slot;
    if (!ob->query_right_weapon()) {
	tell_object(ob, "You need a weapon wielded in right hand before using this skill.\n");
	return 1;
    }
     if(!str && ob->query_attack()) {
        str = lower_case(ob->query_attack()->query_name());
     }
     if (!str) {
        tell_object(ob,"Use assault at whom?\n");
        return 1;
     }
     target = present(str, environment(ob));
     if(!target || !living(target) || target == ob) {
        tell_object(ob,capitalize(str)+" is not a valid target.\n");
        return 1;
     }
     wepa = ob->query_right_weapon();
     dama = ob->query_str()+wepa->query_wc()+ob->query_skill("anatomy");
     weapon_skill = ob->query_skills(lower_case(wepa->query_type()+"s"));
     dama = (dama * weapon_skill) / 70;
    if(ob->query_wiz()) tell_object(ob,"Skill: "+weapon_skill+" Dam: "+dama+"\n");
    slot = ({"head", "throat", "neck", "arms", "legs",})[random(5)];
    if(dama > 1000) { dama = 1000; }
    switch(dama) {
	case 0..100:
	tell_object(ob,"You make "+target->query_name()+" see stars with your assault to "+target->query_objective()+" "+slot+".\n");
	tell_object(target, ob->query_name()+" makes you see stars with "+ob->query_objective()+" assault.\n");
	say(ob->query_name()+ "makes "+target->query_name()+" see stars with "+ob->query_name()+" assault to "+target->query_name()+" "+slot+".\n", ({ ob, target, }));
	break;
	case 101..300:
	tell_object(ob,"You walk close to the "+target->query_name()+" and assault "+target->query_name()+" "+slot+".\n");
	tell_object(target, ob->query_name()+" walks close to you and assaults your "+slot+".\n");
	say(ob->query_name()+" walks close to the "+target->query_name()+" and assault "+target->query_objective()+" "+slot+".\n", ({ ob, target, }));
	break;
	case 301..600:
	tell_object(ob,"You jump close to the "+target->query_name()+" and assault "+target->query_objective()+" "+slot+" with mighty hit.\n");
	tell_object(target, ob->query_name()+" jumps close to you and assault your "+slot+" with mighty hit.\n");
	say(ob->query_name()+" jumps close to the "+target->query_name()+" and assault "+target->query_objective()+" "+slot+" with mighty hit.\n", ({ ob, target, }));
	break;
	case 601..1000:
	tell_object(ob,"You manouver close to the "+target->query_name()+" and assault "+target->query_objective()+" "+slot+" with MIGHTY HIT.\n");
	tell_object(target, ob->query_name()+" manouvers close to you and assault your "+slot+" with MIGHTY HIT.\n");
	say(ob->query_name()+" manouvers close to the "+target->query_name()+" and assault "+target->query_objective()+" "+slot+" with MIGHTY HIT.\n", ({ ob, target, }));
    break;
}
if(random(300) < ob->query_skills("focus power")) {
	tell_object(ob,"You FOCUS your POWER to cause extrime PAIN!\n");
	dama = dama*3/2;
}
target->hit_with_spell(dama, "physical", ob);
ob->attack_object(target);
}

fail_skill(str,object ob) {
    object target;
    if (!str) { tell_object(ob,"You fail the skill.\n"); return; }
    target = present(str, environment(ob));
    if (!target) { tell_object(ob,"You fail the skill.\n"); return; }
    tell_object(ob,"You manouver close to " + target->query_name() + ", but miss " + target->query_objective() + " with your assault.\n");
    tell_object(target, ob->query_name() + " tries to ASSAULT you, but misses.\n");
    say(capitalize(ob->query_name()) + " manouvers close to  " + capitalize(target->query_name()) + " but fails to assault.\n", target);
    target->attack_object(ob);
}
