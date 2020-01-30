get_time(str) {
  return random(2)+2;
}
ep_cost() { return 2; }

resolve_skill(str) {
    int dama;
    object target;
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use kick at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target)) {
      write(str+" is not a valid target.\n");
      return 1;
    }
    dama = (this_player()->query_str()+this_player()->query_dex())/4;
    dama = dama/2 + random(dama/2) + 2;
    if(dama > 10) dama = (dama-10) / 2 + 10;
    if(dama < 10) {
      write("You kick " + capitalize(target->query_name()) + " in the knee!\n");
      tell_object(target, capitalize(this_player()->query_name()) +
	" kicks you in the knee!\n");
      say(capitalize(this_player()->query_name()) + " kicks "+
	capitalize(target->query_name()) + " in the knee!\n", target);
    } else {
      write("Your powerful kick impacts on "+capitalize(target->query_name())+
	"'s stomach with a nasty sound!\n");
      tell_object(target, this_player()->query_name()+
	" brutally kicks you in the stomach! OUCH!\n");
      say(capitalize(this_player()->query_name()) + " kicks "+
	capitalize(target->query_name()) + " in the stomach!\n", target);
    }
    if(dama > 20) { dama=20; }
    if(this_player()->query_attack() != target) this_player()->attack_object(target);
    target->hit_with_spell(dama);
}

fail_skill(str) {
    object target;
    if(!str) {
	write("Use kick at who?\n");
	return 1;
    }
    if(random(100) < this_player()->query_skills("kick")) {
	resolve_skill(str);
	return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You try to kick " + target->query_name() + ", but miss.\n");
    tell_object(target, this_player()->query_name() + " tries to KICK you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " tries to kick " + target->query_name() +
       ", but misses.\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}
