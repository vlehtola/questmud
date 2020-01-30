get_time() {
  return random(2)+4;
}
query_type() { return "offensive"; }

ep_cost() { return 5; }

resolve_skill(str, object ob) {
    int dama, weapon_skill;
    object wepa,limb,target;
    string slot;
    if(!ob)ob=this_player();
    if (!ob->query_right_weapon()) {
        tell_object(ob, "You need a weapon wielded in right hand before using this skill.\n");
        return 1;

    }

     if(!str && ob->query_attack()) {
        str = lower_case(ob->query_attack()->query_name());
     }
     if (!str) {
        tell_object(ob,"Use sky strike at whom?\n");
        return 1;
     }
     target = present(str, environment(ob));
     if(!target || !living(target) || target == ob) {
        tell_object(ob,capitalize(str)+" is not a valid target.\n");
        return 1;
     }
     wepa = ob->query_right_weapon();
     dama_skill = ob->query_skills("claws storm");
     dama2_skill = ob->query_skills("dragon blow");
     focus = ob->query_skills("focused sky strike");
     dama = ob->query_str()+ob->query_dex()*2;
     if(dama_skill) {
     dama = (dama * dama_skill + dama2_skill)/75;
    if(ob->query_wiz()) tell_object(ob,"Skill: "+weapon_skill+" Dam: "+dama+"\n");
    if(dama > 800) { dama = 800; }
  if(tp->query_skills("focused sky strike")+tp->query_skills("claws storm") > random(700)) {
    write("You scream and focus all your strength.\n");
    dama = (dama + (focus*2));
    switch(dama) {
        case 0..100:
        tell_object(ob,"You weakly jump in the air and strike at the chest of "+target->query_name()+"!\n");
        tell_object(target, ob->query_name()+" jumps weakly in the air and strike knuckles right in to your face!\n");
        tell_room(environment(ob), ob->query_name()+" strikes
"+target->query_name()+"'s chest with force but it just bounces off!\n", ({ ob, target, }));
    break;
    case 101..200:
    tell_object(ob, "You jump and smack your knuckles in the
"+target->query_name()+"'s face!\n");
    tell_object(target, ob->query_name()+" plunges "+ob->query_objective()+"
chaos "+wepa->query_type()+" in your exposed chest.\n");
    tell_room(environment(ob), ob->query_name()+" plunges
"+ob->query_objective()+" chaos "+wepa->query_type()+" in the chest of
"+target->query_name()+".\n", ({ ob, target}));
    break;
    case 201..400:
    tell_object(ob, "You bring down your chaos "+wepa->query_type()+" in a
huge arc and smash it directly at the neck of "+target->query_name()+".\n");
    tell_object(target, ob->query_name()+" brings down
"+ob->query_objective()+" chaos "+wepa->query_type()+" in huge and smashes
your neck.\n");
    tell_room(environment(ob), ob->query_name()+" brings down
"+ob->query_objective()+" chaos "+wepa->query_type()+" in huge arc and smashes
it directly at the neck of "+target->query_name()+".\n", ({ ob, target}));
    break;
    case 401..600:
    tell_object(ob, "You bring down your chaos "+wepa->query_type()+" in a
huge arc and smash it directly at the neck of "+target->query_name()+".\n");
    tell_object(target, ob->query_name()+" brings down
"+ob->query_objective()+" chaos "+wepa->query_type()+" in huge and smashes
your neck.\n");
    tell_room(environment(ob), ob->query_name()+" brings down
"+ob->query_objective()+" chaos "+wepa->query_type()+" in huge arc and smashes
it directly at the neck of "+target->query_name()+".\n", ({ ob, target}));
    break;
    case 601..800:
    tell_object(ob, "Your chaos "+wepa->query_type()+" glows brightly as it
sinks deep in the flesh of "+target->query_name()+".\n");
    tell_object(target, ob->query_name()+"'s chaos "+wepa->query_name()+"
glows brightly as it sinks deep in your flesh.\n");
        tell_room(environment(ob), ob->query_name()+"'s chaos
"+wepa->query_name()+" glows brightly as it sinks deep in the flesh of
"+target->query_name()+".\n", ({ ob, target}));
    }
    target->hit_with_spell(dama, "physical", ob);
    if(ob->query_attack() != target) {
        ob->attack_object(target);
}
}

fail_skill(str,object ob) {
    object target;
    if(!ob)ob=this_player();
    if (!str) { tell_object(ob,"You fail the skill.\n"); return; }
    target = present(str, environment(ob));
    if (!target) { tell_object(ob,"You fail the skill.\n"); return; }
    tell_object(ob,"You try to chaos strike "+str+".\n");
    tell_object(target, ob->query_name() + " tries to chaos strike you!\n");
    tell_room(environment(ob), capitalize(ob->query_name()) + " tries to chaos
strike " + capitalize(target->query_name()) + " but fails.\n", ({ target, ob
}));
    target->attack_object(ob);

}
