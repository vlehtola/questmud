get_time() {
  return random(3)+2;
}

query_type() { return "offensive"; }
ep_cost() { return 25; }

resolve_skill(target) {
    int dama, weapon_skill;
    object wepa;
    if (this_player()->query_right_weapon()) {
     if(!living(target)) {
	write(target->short()+" is not a living thing.\n");
	return 1;
     }
      if(!target) {
        write("Use strike at whom?\n");
        return 1;
      }
        wepa = this_player()->query_right_weapon();
        dama = 50 + (random((this_player()->query_str() / 2) +
                          call_other(wepa, "query_wc") + wepa->query_weight())*3/2);
        weapon_skill =
		this_player()->query_skills(lower_case(wepa->weapon_names(wepa->query_type())+"s"));
        dama = (dama * weapon_skill) / 30;
	if(dama > 400) {
          write(target->query_name()+" grunts in pain as you mercilessly aim "+
            "a MIGHTY strike upon "+target->query_possessive()+" shoulder!\n");
	} else if(dama > 200) {
          write("You step forward and BRUTALLY strike " +
		capitalize(target->query_name()) + " with your " + wepa->query_name() + "!\n");
	} else {
          write("You move swiftly and skillfully strike "+
                capitalize(target->query_name())+"!\n");
	}
        tell_object(target, "You scream in pain as " + capitalize(this_player()->query_name()) +
	    " quickly steps towards you and STRIKES with " +this_player()->query_possessive() +
            " " + wepa->query_name() + "!\n");
        say(capitalize(this_player()->query_name()) + " quickly moves towards " +
		capitalize(target->query_name()) + " and STRIKES " + target->query_objective() + "!\n", target);
        if(dama > 450) { dama = 450; }
        target->hit_with_spell(dama);
    } else {
        write("You need a weapon in your right hand to perform this skill.\n");
        return 1;
    }
}

fail_skill(target) {
    write("You step towards " + target->query_name() + ", but miss " + target->query_pronoun() + " with your strike.\n");
    tell_object(target, this_player()->query_name() + " tries to STRIKE you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " stumbles towards " + capitalize(target->query_name()) + " and strikes air.\n", target);
    target->attack_object(this_player());
}
