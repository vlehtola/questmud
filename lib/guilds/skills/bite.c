get_time(str) {
  return random(4)+4;
}
ep_cost() { return 5; }
query_type() { return "offensive"; }

resolve_skill(str) {
    int dama;
    object target;
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use bite at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      write(str+" is not a valid target.\n");
      return 1;
    }
    dama = (this_player()->query_str()+this_player()->query_size()*4);
    dama = dama/2 + random(dama/2) + 2;


    if(dama < 500) {
      write("You bite " + capitalize(target->query_name()) + " harmfully!\n");
      tell_object(target, capitalize(this_player()->query_name()) +" bites you harmfully!\n");
      say(capitalize(this_player()->query_name()) + " bites "+capitalize(target->query_name()) + " harmfully!\n", target);
    } else {
      write("Your powerful bite makes "+capitalize(target->query_name())+" scream in pain as sound of breaking bones can be heard!\n");
      tell_object(target, this_player()->query_name()+" bites you powerfully breaking bones and tendons!\n");
      say(capitalize(this_player()->query_name()) + " bites "+capitalize(target->query_name()) + " making sound of breaking bones and tendons!\n", target);
    }
    if(this_player()->query_attack() != target) this_player()->attack_object(target);
    target->hit_with_spell(dama, "physical");
}

fail_skill(str) {
    object target;
    if(!str) {
        write("Use bite at who?\n");
        return 1;
    }
    if(random(150) < this_player()->query_skills("bite")) {
        resolve_skill(str);
        return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You try to bite " + target->query_name() + ".\n");
    tell_object(target, this_player()->query_name() + " tries to bite you!\n");
    say(capitalize(this_player()->query_name()) + " tries to bite " + target->query_name() +".\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}
