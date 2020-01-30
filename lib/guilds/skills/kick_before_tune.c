get_time(str) {
  return random(2)+2;
}
ep_cost() { return 2; }
query_type() { return "offensive"; }

resolve_skill(str, ob) {
    int dama;
    object target;
    if(!ob)ob=this_player();
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      tell_object(ob, "Use kick at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      tell_object(ob, str+" is not a valid target.\n");
      return 1;
    }
    dama = (this_player()->query_str()+this_player()->query_dex())/3;
    dama = dama + random(dama/2) + 2;

    if(dama > 20) dama = (dama-20) / 2 + 20;

    if(dama < 10) {
      tell_object(ob, "You kick " + capitalize(target->query_name()) + " in the knee!\n");
      tell_object(target, capitalize(this_player()->query_name()) +
	" kicks you in the knee!\n");
      say(capitalize(this_player()->query_name()) + " kicks "+
	capitalize(target->query_name()) + " in the knee!\n", target);
    } else {
      tell_object(ob, "Your powerful kick impacts on "+capitalize(target->query_name())+
	"'s stomach with a nasty sound!\n");
      tell_object(target, this_player()->query_name()+
	" brutally kicks you in the stomach! OUCH!\n");
      say(capitalize(this_player()->query_name()) + " kicks "+
	capitalize(target->query_name()) + " in the stomach!\n", target);
    }
    if(dama > 40) { dama=40; }
    if(this_player()->query_attack() != target) this_player()->attack_object(target);
    target->hit_with_spell(dama, "physical");

/*
 DISABLED due to abuse //Celtron

    if(!random(1000)) {
     this_player()->set_mastery("Offensive maneuvers",(this_player()->query_mastery()["Offensive maneuvers"] + 1));
   }
    dama += (this_player()->query_mastery()["Offensive maneuvers"]/10);
*/
}

fail_skill(str, ob) {
    object target;
    if(!ob)ob=this_player();
    if(!str) {
	tell_object(ob, "Use kick at who?\n");
	return 1;
    }
    if(random(100) < this_player()->query_skills("kick")) {
	resolve_skill(str);
	return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    tell_object(ob, "You try to kick " + target->query_name() + ", but miss.\n");
    tell_object(target, this_player()->query_name() + " tries to KICK you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " tries to kick " + target->query_name() +
       ", but misses.\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}
