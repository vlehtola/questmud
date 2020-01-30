#define TREMENDOUS "/guilds/skills/tremendous_blow"

get_time() {
  return random(3)+3;
}
query_type() { return "offensive"; }
ep_cost() { return 5; }

resolve_skill(str) {
    int dama, weapon_skill;
    object wepa,limb,target;
    if (this_player()->query_right_weapon()) {
     if(!str && this_player()->query_attack()) {
        str = lower_case(this_player()->query_attack()->query_name());
     }
     if (!str) {
        write("Use strike at whom?\n");
        return 1;
     }
     target = present(lower_case(str), environment(this_player()));
     if(!target || !living(target) || target == this_player()) {
        write(capitalize(str)+" is not a valid target.\n");
        return 1;
     }

     if(this_player()->query_skills("tremendous blow") > random(160) && target->query_hp() < target->query_max_hp() / 2) {
        return TREMENDOUS->resolve_skill(str);
     }

        wepa = this_player()->query_right_weapon();
        dama = 20 + this_player()->query_str()/2*wepa->query_wc() / 40;
        weapon_skill =
          this_player()->query_skills(lower_case(wepa->query_type()+"s"));
        dama = (dama * weapon_skill) / 70;
   if(!this_player()->query_npc()) {
     if(!random(this_player()->query_mastery()["Offensive maneuvers"]+50)) {
      this_player()->set_mastery("Offensive maneuvers",(this_player()->query_mastery()["Offensive maneuvers"] + 1));
     }
     dama += this_player()->query_mastery()["Offensive maneuvers"];
    }
        if(dama > 250) { dama = 250; }
        if(this_player()->query_berserk() && this_player()->query_attack()) {
          write("The taste of blood fills your mouth as you focus your fury to the blow.\n");
          dama += 150;
        }
        if(this_player()->query_tester()) write("Skill: "+weapon_skill+" Dam: "+dama+"\n");
        if(dama > 150) {
          write(target->query_name()+" grunts in pain as you mercilessly aim "+
            "a MIGHTY strike upon "+target->query_possessive()+" shoulder!\n");
        } else if(dama > 100) {
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
        if(dama > target->query_hp()*(100-target->query_resists(0))/100+2 && target->query_npc()) {
          tell_room(environment(this_player()), call_other("/guilds/skill_obj/strike_death_msg","get_msg",target));
          move_object(clone_object("/world/objects/blood"), environment(this_player()));
          limb = clone_object("/world/objects/limb");
          limb->set_short("Mutilated head of "+target->short());
          move_object(limb,environment(this_player()));
          dama = dama *2;
        }
        this_player()->attack_object(target, 1);
        target->hit_with_spell(dama, "physical");
        if(target) {
          if(this_player()->query_skills("double strike") > random(110)) {
            write("...and strike again with a quick hit.\n");
            say("...and strikes again with a quick hit.\n");
            dama = dama * this_player()->query_skills("double strike") / 200;
            if(dama > 200) dama = 200; /* ei voi ees olla */
            target->hit_with_spell(dama, "physical");
          }
        }
    } else {
        write("You need a weapon in your right hand to perform this skill.\n");
        return 1;
    }
}

fail_skill(str) {
    object target;
    if (!str) { write("You fail the skill.\n"); return; }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You step towards " + target->query_name() + ", but miss " +
        target->query_objective() + " with your strike.\n");
    tell_object(target, this_player()->query_name() + " tries to STRIKE you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " stumbles towards " + capitalize(target->query_name()) + " and strikes air.\n", target);
    target->attack_object(this_player());
}
