get_time(str) {
  return random(3)+3;
}
ep_cost() { return 5; }
query_type() { return "offensive"; }

resolve_skill(string str) {
    int skill;
    object target, weapon;
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use disarm at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target)) {
      write(str+" is not a valid target.\n");
      return 1;
    }
  if(!this_player()->query_right_weapon()) {
    write("You need a weapon in your right hand to perform this skill.\n");
    return 1;
  }

  weapon = target->query_weapon();
  if(!weapon) {
    write(target->query_name()+" has no weapon!\n");
    return 1;
  }
  if(target->query_log()) {
  write(target->query_name()+" laughs at your pathetic disarm attempt!\n");
  this_player()->attack_object(target);
  return 1;
  }
  skill = this_player()->query_skills("disarm");
  if(random(skill) > target->query_level() &&
     random(skill) > target->query_level()) {
    write("You make a swift maneuver and disarm "+target->query_name()+".\n");
    tell_object(target, this_player()->query_name()+" suddenly disarms you!\n");
    say(this_player()->query_name()+" skillfully disarms "+target->query_name()+".\n", target);
    target->stop_wielding(weapon);
    weapon->set_wielder();
  } else {
    write("You fail to disarm your opponent.\n");
    say(this_player()->query_name()+" makes a disarm attempt but fails.\n");
  }

  if(this_player()->query_attack() != target) this_player()->attack_object(target);

}

fail_skill(str) {
  write("You fail the skill.\n");
}
