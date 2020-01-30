get_time(str) {
  return random(2)+1;
}
ep_cost() { return 3; }

resolve_skill(target) {
    int dama;
    if(!target) {
      write("Use kick at who?\n");
      return 1;
    }
    dama = (this_player()->query_str() / 3 + this_player()->query_dex()/2);
    dama = dama/2 + random(dama) + 5;
    if(dama < 60) {
      write("You kick " + capitalize(target->query_name()) + " in the knee!\n");
      tell_object(target, capitalize(this_player()->query_name()) +
	" kicks you in the knee!\n");
      say(capitalize(this_player()->query_name()) + " kicks "+
	capitalize(target->query_name()) + " in the knee!\n", target);
    } else {
      write("Your powerful kick impacts "+capitalize(target->query_name())+
	"'s stomach with a nasty sound!\n");
      tell_object(target, this_player()->query_name()+
	" brutally kicks you in the stomach! OUCH!\n");
      say(capitalize(this_player()->query_name()) + " kicks "+
	capitalize(target->query_name()) + " in the stomach!\n", target);
    }
    if(dama > 100) { dama=100; }
    target->hit_with_spell(dama);
    this_player()->attack_object(target);
}

fail_skill(target) {
    if(!target) {
	write("Use kick at who?\n");
	return 1;
    }
    if(random(100) < this_player()->query_skills(call_other("/obj/skillfun","skill_nums","kick"))) {
	resolve_skill(target);
	return 1;
    }
    write("You try to kick " + target->query_name() + ", but miss.\n");
    tell_object(target, this_player()->query_name() + " tries to KICK you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " tries to kick " + capitalize(target->query_name()) + ", but misses.\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}
