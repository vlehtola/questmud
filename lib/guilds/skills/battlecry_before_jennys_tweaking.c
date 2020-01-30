get_time() {
  return random(5)+3;
}

query_type() { return "offensive"; }
ep_cost() { return 15; }

resolve_skill(str) {
    int dama, weapon_skill,i;
    object wepa,ob,target;
    if(!str) { write("Use battlecry at whom?\n"); return; }
    if (this_player()->query_attack()) {
	write("You cannot use battlecry while in combat.\n");
	return 1;
    }
    target = present(str, environment(this_player()));
    if (this_player()->query_right_weapon()) {
      if(!target) {
        write("Use battlecry at whom?\n");
        return 1;
      }
        wepa = this_player()->query_right_weapon();
        dama = 10 + (random((this_player()->query_str() / 3) +
                          call_other(wepa, "query_wc") + wepa->query_weight()));
        weapon_skill =this_player()->query_skills(lower_case(wepa->weapon_names(wepa->query_type())+"s"));
        dama = (dama * weapon_skill) / 50;
	write(target->query_name()+" is STUNNED by the force of your mighty roar!\n");
	tell_object(target, this_player()->query_name() +" lets out a mighty roar and aims a powerful "+
	  "hit on you!\n");
        say("You get STUNNED by the force of "+capitalize(this_player()->query_name()) +
	  " roar while " +this_player()->query_pronoun()+" rushes towards "+
	  capitalize(target->query_name()) + " and attacks " + target->query_possessive() + "!\n",target);
        if(dama > 200) { dama = 200; }
        target->hit_with_spell(dama);
        this_player()->attack_object(target, 1);
	ob = all_inventory(environment(this_player()));
	while(i<sizeof(ob)) {
	  if(living(ob[i]) && ob[i] != this_player()) {
	    ob[i]->set_stunned(3+random(5));
	    if(ob[i]->query_npc()) {
	      ob[i]->attack_object(this_player());
	    }
	  }
	  i += 1;
        }
    } else {
        write("You need a weapon in your right hand to perform this skill.\n");
        return 1;
    }
}

fail_skill(target) {
    write("Your pathetic scream doesn't affect anybody and you miss with your weapon.\n");
    tell_object(target, this_player()->query_name() + " tries to hit you while screaming, but fails.\n");
    say(capitalize(this_player()->query_name()) + " lets out a pathetic scream and pitifully tries to attack "
	+ target->query_name()+".\n");
    target->attack_object(this_player());
}
