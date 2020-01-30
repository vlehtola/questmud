// Moonstar. Maritial artists offensive skill. 22.02.2004

#define MASTERY_D "/daemons/mastery_d"

get_time() {
  return random(3)+3;
}
query_type() { return "offensive"; }
ep_cost() { return 8; }

resolve_skill(str) {
    int dama, dama2, dama3, weapon_skill;
    object wepa,limb,target;
    if (!this_player()->query_right_weapon()) {
        write("You need a weapon in your right hand to perform this skill.\n");
        return 1;
    }

    if(!str && this_player()->query_attack()) {
       str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
       write("Use whirling slash at whom?\n");
       return 1;
    }
    target = present(lower_case(str), environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
       write(capitalize(str)+" is not a valid target.\n");
       return 1;
    }


    wepa = this_player()->query_right_weapon();
    dama = 30 + this_player()->query_str()/2*wepa->query_wc() / 40;
    weapon_skill = this_player()->query_skills(lower_case(wepa->query_type()+"s"))*2/3;
    weapon_skill += this_player()->query_skills("whirling slash")*2/3;
    dama = (dama * weapon_skill) / 70;
    dama += this_player()->query_skills("vital points")*2;
    dama = dama*4/5 + random(dama/5);

    if(dama > 400) { dama = 400; }
    if(this_player()->query_berserk() && this_player()->query_attack()) {
      write("Your eyes flashes in berserk as you prepare your slash!\n");
      dama += 150;
    }

    dama += dama * MASTERY_D->mastery("Offensive maneuvers",this_player(),target)/200;
    if(this_player()->query_tester()) write("Skill: "+weapon_skill+" Dam: "+dama+"\n");
    if(dama > 800) {
      write(target->query_name()+" screams in PAIN as you unleash "+
          "your slash upon "+target->query_possessive()+" head!\n");
    say(capitalize(this_player()->query_name()) + " screams and runs towards " +
                capitalize(target->query_name()) + " and SLASHES with FORCE " + target->query_name() + " head!\n", target);
    } else if(dama > 300) {
          write("You run towards " +
 capitalize(target->query_name()) + " and SLASH, SLASH, SLASH " + capitalize(target->query_name()) + " with your " + wepa->query_name() + "!\n");
    say(capitalize(this_player()->query_name()) + " runs towards " +
                capitalize(target->query_name()) + " and SLASHES, SLASHES, SLAHES " + target->query_name() + "!\n", target);
    } else {
          write("You weakly whirl and slash "+
          capitalize(target->query_name())+"!\n");
    say(capitalize(this_player()->query_name()) + " sneaks behind " +
                capitalize(target->query_name()) + " and weakly slashes " + target->query_name() + ".\n", target);
     }
    tell_object(target, "You almoust fall down as " + capitalize(this_player()->query_name()) +
           " SLASHES your head with " +this_player()->query_possessive() +
            " " + wepa->query_name() + "!\n");


    if(target) {
       if(this_player()->query_skills("crushing") > random(200)) {
            write("Suddenly you turn back and CRUSH "+ capitalize(target->query_name()) + " with your " + wepa->query_name() + "!\n");
            say("suddenly slashes again with crushing sound!\n");
            dama2 = (this_player()->query_skills("crushing") + this_player()->query_dex());
            if(dama2 > 350) dama2 = 350;
            dama += dama2;
            }

    if(target) {
       if(this_player()->query_skills("finishing move") > random(300)) {
            write("You focus all your strength and DECIPITATE " + capitalize(target->query_name()) + " with your " + wepa->query_name() + "!\n");
            say("focuses and DECIPITATES " + capitalize(target->query_name()) + "!\n");
            dama3 = this_player()->query_skills("finishing move") + this_player()->query_skills("whirling slash") + this_player()->query_skills("vital points") + this_player()->query_skills("crushing");
            dama += dama3;
}
}
     }
    if(dama > 1250) { dama = 1250; }
     if(this_player()->query_wiz()) write("Dam: "+dama+"\n");
     this_player()->attack_object(target, 1);
     target->hit_with_spell(dama, "physical");
}

fail_skill(str) {
    object target;
    if (!str) { write("You fail the skill.\n"); return; }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You step towards " + target->query_name() + ", but miss " +
        target->query_objective() + " with your strike.\n");
    tell_object(target, this_player()->query_name() + " tries to SLASH you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " runs towards " + capitalize(target->query_name()) + " but falls!\n", target);
    target->attack_object(this_player());
}
