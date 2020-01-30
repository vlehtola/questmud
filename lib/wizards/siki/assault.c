
get_time() {
  return random(2)+4;
}
query_type() { return "offensive"; }
ep_cost() { return 10; }

resolve_skill(str) {
    int dama, weapon_skill;
    object wepa,limb,target;
    string slot;
    if (!this_player()->query_right_weapon()) {
	write("You need a weapon wielded in right hand before using this skill.\n");
	return 1;
    }
     if(!str && this_player()->query_attack()) {
        str = lower_case(this_player()->query_attack()->query_name());
     }
     if (!str) {
        write("Use assault at whom?\n");
        return 1;
     }
     target = present(str, environment(this_player()));
     if(!target || !living(target) || target == this_player()) {
        write(capitalize(str)+" is not a valid target.\n");
        return 1;
     }
     wepa = this_player()->query_right_weapon();
     dama = this_player()->query_str()+wepa->query_wc()+this_player()->query_skill("anatomy");
     weapon_skill = this_player()->query_skills(lower_case(wepa->query_type()+"s"));
     dama = (dama * weapon_skill) / 70;
     if(!random(this_player()->query_mastery()["Offensive maneuvers"]+50) && !this_player()->query_npc()) {
     this_player()->set_mastery("Offensive maneuvers",(this_player()->query_mastery()["Offensive maneuvers"] + 1));
     }
    if(!this_player()->query_npc()) { dama += this_player()->query_mastery()["Offensive maneuvers"]; }
    if(this_player()->query_wiz()) write("Skill: "+weapon_skill+" Dam: "+dama+"\n");
    slot = ({"head", "throat", "neck", "arms", "legs",})[random(6)];
    switch(dama) {
	case 0..100:
	write("You make "+target->query_name()+" see stars with your assault to "+target->query_pronoun()+" "+slot+".\n");
	tell_object(target, this_player()->query_name()+" makes you see stars with "+this_player()->query_pronoun()+" assault.\n");
	say(this_player()->query_name()+ "makes "+target->query_name()+" see stars with "+this_player()->query_name()+" assault to "+target->query_name()+" "+slot+".\n", ({ this_player(), target, }));
	break;
	case 101..300:
	write("You walk close to the "+target->query_name()+" and assault "+target->query_name()+" "+slot+".\n");
	tell_object(target, this_player()->query_name()+" walks close to you and assaults your "+slot+".\n");
	say(this_player()->query_name()+" walks close to the "+target->query_name()+" and assault "+target->query_pronoun()+" "+slot+".\n", ({ this_player(), target, }));
	break;
	case 301..600:
	write("You jump close to the "+target->query_name()+" and assault "+target->query_pronoun()+" "+slot+" with mighty hit.\n");
	tell_object(target, this_player()->query_name()+" jumps close to you and assault your "+slot+" with mighty hit.\n");
	say(this_player()->query_name()+" jumps close to the "+target->query_name()+" and assault "+target->query_pronoun()+" "+slot+" with mighty hit.\n", ({ this_player(), target, }));
	break;
	case 601..1000:
	write("You manouver close to the "+target->query_name()+" and assault "+target->query_pronoun()+" "+slot+" with MIGHTY HIT.\n");
	tell_object(target, this_player()->query_name()+" manouvers close to you and assault your "+slot+" with MIGHTY HIT.\n");
	say(this_player()->query_name()+" manouvers close to the "+target->query_name()+" and assault "+target->query_pronoun()+" "+slot+" with MIGHTY HIT.\n", ({ this_player(), target, }));
    break;
}
if(random(300) < this_player()->query_skills("focus power")) {
	write("You FOCUS your POWER to cause extrime PAIN!\n");
	dama = dama*3/2;
}
this_player()->attack_object(target);
target->hit_with_spell(dama, "physical");
}

fail_skill(str) {
    object target;
    if (!str) { write("You fail the skill.\n"); return; }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You manouver close to " + target->query_name() + ", but miss " + target->query_objective() + " with your assault.\n");
    tell_object(target, this_player()->query_name() + " tries to ASSAULT you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " manouvers close to  " + capitalize(target->query_name()) + " but fails to assault.\n", target);
    target->attack_object(this_player());
}
