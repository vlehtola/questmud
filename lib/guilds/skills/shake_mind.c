#define MASTERY_D "/daemons/mastery_d"
#define SM_LVL_LIMIT 30
#define SM_SP_NEEDED 100

get_time(str) {
  return random(3)+2;
}
query_type() { return "offensive"; }

ep_cost() { return 1; }

resolve_skill(str) {
    int att,def, sp_needed;
    object target;

    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use shake mind at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      write(str+" is not a valid target.\n");
      return 1;
    }

    if(target->query_stun()) {
        write(target->query_name()+" is already stunned.\n");
        return 1;
    }

    if(target->query_level() > SM_LVL_LIMIT + (MASTERY_D->query_mastery("Expanded mind",this_player())+10)/20 ) {
        write(target->query_name()+"'s mind is too strong.\n");
        if(target->query_attack() != this_player())target->attack_object(this_player());
        if(this_player()->query_attack() != target)this_player()->attack_object(target);
        return 1;
    }
        if(target->query_undead()) {
                write(target->query_name()+" is undead and the mindwave reflects on you!\n");
                this_player()->set_stunned(random(10)+1);
                if(target->query_attack() != this_player())target->attack_object(this_player());
                return 1;
        }


    sp_needed = SM_SP_NEEDED - MASTERY_D->query_mastery("Power of the mind",this_player())/3;

    if(this_player()->query_sp() < sp_needed) {

        write("You lack the mental strength to accomplish this attack.\n");
        return 1;
}
this_player()->reduce_sp(sp_needed);

        MASTERY_D->mastery("Expanded mind",this_player(),target);

        att = this_player()->query_int();
        att += this_player()->query_skills("shake mind");
        att += this_player()->query_skills("knowledge of mind");
        att += MASTERY_D->mastery("Power of the mind",this_player(),target)/3;
        if(this_player()->query_mentaldenial()) {
                att *= 2;
                this_player()->remove_denial();
        }

        att /= 2;
        att += random(att);

        def = target->query_wis();
        def += target->query_skills("mental block");
        def /= 2;
if(target->query_attack() == this_player()) def *= 2;
        def += random(def);

if(att < def) {
        write("Your attack is too weak and "+target->query_name()+" blocks it.\n");
        tell_object(target,this_player()->query_name()+"'s mental attack doesnt even cause an headache for you!\n");
        say(this_player()->query_name()+" tries to shake "+target->query_name()+"'s mind but fails pityfully.\n",target);
        if(target->query_attack() != this_player())target->attack_object(this_player());
        if(this_player()->query_attack() != target)this_player()->attack_object(target);
        return 1;

}

//lenght of stun
att = random(2)+1;

    write("You shake "+target->query_name()+"'s mind and force "+target->query_objective()+" into unstable state!\n");
    tell_object(target,this_player()->query_name()+" attacks directly into your mind and forces you into unstable state!\n");
    say(this_player()->query_name()+" shakes "+target->query_name()+"'s mind and forces "+target->query_objective()+" into unstable state!\n",target);
    target->set_stunned(random(att)+1);
    //if(target->query_attack() != this_player())target->attack_object(this_player());
    if(this_player()->query_attack() != target) this_player()->attack_object(target);

}

fail_skill(str) {
    object target;
    if(!str) {
        write("Use shake mind at who?\n");
        return 1;
    }
    if(random(100) < this_player()->query_skills("shake mind")) {
        resolve_skill(str);
        return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You concentrate on shaking " + target->query_name() + "'s mind, but fail.\n");
    tell_object(target, this_player()->query_name() + " concentrates a moment but suddenly shakes "+this_player()->query_possessive()+" head.\n");
    say(capitalize(this_player()->query_name()) + " concentrates for a moment but suddenly shakes "+this_player()->query_possessive()+" head.\n", target);
    //target->attack_object(this_player());
    //this_player()->attack_object(target);
}
