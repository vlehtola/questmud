get_time(str) {
  return random(2)+1;
}
ep_cost() { return 3; }
query_type() { return "neutral"; }

resolve_skill(str) {
    object target,wepa;
    if(!str) {
      write("Use at who?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target)) {
      write(str+" is not a valid target.\n");
      return 1;
    }
  write("Against "+target->query_name()+" you need:\n");
  wepa = target->query_right_weapon();
  if(this_player()->query_right_weapon()) {
    if(!target->query_right_weapon()&& !target->query_animal()) write("slicing blade\n");
    if(!target->query_right_weapon()&& target->query_animal()) write("bloodhunt\n");
    if(wepa) {
      if(wepa->query_type() == 1) write("sneaky wind\n");
      if(wepa->query_type() == 2) write("sharp lightning\n");
      if(wepa->query_type() == 3) write("invisible storm\n");
    }
  }
  if(!wepa) write("sly hands\nsticky hands\n");
  if(wepa) {
    if(wepa->query_type() == 1) write("sneaky hands\nthunderclap\n");
    if(wepa->query_type() == 2) write("blazing speed\nmoving rock\n");
    if(wepa->query_type() == 3) write("flying hands\ndragonclaws\n");
  }
}

fail_skill(str) {
    object target;
    if(!str) {
	write("Use at who?\n");
	return 1;
    }
    write("You fail the skill.\n");
}
