#define MASTERY_D "/daemons/mastery_d"
#define SP_NEEDED 50
#define PSI_LEVELLIMIT 30
#define CHARM_MODIFIER 20
get_time(str) {
  return random(2)+2;
}
ep_cost() { return 5; }
query_type() { return "neutral"; }

resolve_skill(str) {
    int att,def, sp_needed;
    object target;

    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      write("Use charm at whom?\n");
      return 1;
    }


    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      write(str+" is not a valid target.\n");
      return 1;
    }

    if(!target->query_npc()) {
        write("You can not charm other players!\n");
        return 1;
        }

    if(target->query_level() > PSI_LEVELLIMIT+(MASTERY_D->query_mastery("Expanded mind",this_player())+10)/15) {
        write(target->query_name()+"'s mind is too strong to be charmed!.\n");
        if(target->query_attack() != this_player())target->attack_object(this_player());
        if(this_player()->query_attack() != target)this_player()->attack_object(target);
        return 1;
        }
        if(target->query_undead()) {
                write(target->query_name()+" is undead and the mindwave reflects on you !\n");
                this_player()->set_stunned(random(10)+1);
                if(target->query_attack() != this_player())target->attack_object(this_player());
                return 1;
        }

    if(target->query_charmed()) {
        write(target->query_name()+" is already affected by a charm.\n");
        return 1;
    }

    sp_needed = SP_NEEDED - MASTERY_D->query_mastery("Power of the mind",this_player())/3;

    if(this_player()->query_sp() < sp_needed) {

        write("You lack the mental strength to accomplish this attack.\n");
        return 1;
    }
        this_player()->reduce_sp(sp_needed);

        att = this_player()->query_int();
        att += this_player()->query_skills("charm");
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
        //muuta descit

          write(target->query_name()+" resists your attempt to charm "+target->query_objective()+".\n");
          say(this_player()->query_name()+" tries to charm "+target->query_name()+" but fails miserably.\n");

          return 1;

        }


        write("You charm "+target->query_name()+" forcing "+target->query_objective()+" to calm down.\n");
        say(this_player()->query_name()+" charms "+target->query_name()+" forcing "+target->query_objective()+" to calm down.\n");
        target->stop_all();
        target->stop_all_hunting();
        this_player()->stop_fight();
        clone_object("/guilds/psi/specials/charm_shadow")->start(target);
}

fail_skill(str) {
    object target;
    if(!str) {
        write("Use charm at who?\n");
        return 1;
    }
    if(random(100) < this_player()->query_skills("charm")) {
        resolve_skill(str);
        return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    write("You lose your concentration and fail the skill.\n");

}
