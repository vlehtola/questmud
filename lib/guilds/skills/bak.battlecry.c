get_time() {
  return random(3)+2;
}

query_type() { return "offensive"; }
ep_cost() { return 8; }

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
        say(capitalize(target->query_name())+" gets STUNNED by the force of "+this_player()->query_name()+"'s roar while "+this_player()->query_pronoun()+" rushes towards "+capitalize(target->query_name())+" and attacks "+target->query_objective()+"!\n",target);
        if(dama > 250) { dama = 250; }
        target->hit_with_spell(dama);
        this_player()->attack_object(target, 1);
        target->set_stunned(2+random(4));
        target->attack_object(this_player(),1);

    } else {
        write("You need a weapon in your right hand to perform this skill.\n");
        return 1; 
    }
}

fail_skill(target) {
    write("Your pathetic scream doesn't affect anybody and you miss with your weapon.\n");
    tell_object (target, this_player()->query_name() + " tries to hit you while screaming, but fails.\n");
    say(capitalize(this_player()->query_name()) + " lets out a pathetic scream and pitifully tries to attack "+
        capitalize(target->query_name()),target);
    target->attack_object(this_player());
}
