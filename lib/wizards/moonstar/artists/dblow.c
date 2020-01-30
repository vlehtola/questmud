
get_time(str) {
  return random(2)+2;
}
ep_cost() { return 2; }
query_type() { return "offensive"; }

resolve_skill(str, ob) {
    int dama;
    object target;
    if(!ob)ob=this_player();
    if(!str && this_player()->query_attack()) {
      str = lower_case(this_player()->query_attack()->query_name());
    }
    if (!str) {
      tell_object(ob, "Use Dragon blow at whom?\n");
      return 1;
    }
    target = present(str, environment(this_player()));
    if(!target || !living(target) || target == this_player()) {
      tell_object(ob, str+" is not a valid target.\n");
      return 1;
    }
    dama = (this_player()->query_dex()+this_player()->query_str())/2;
    dama = dama + random(dama/2) + 5;
 if(this_player()->query_skills("whirlwind") > random(300)) {
    write("You jump in the air and whirl in RAGE.\n");
    dama = dama + 80;
   if(dama > 160) dama = (dama-150) / 2 + 150;

if(dama < 90) {
      tell_object(ob, "You scream 'kiaa' and your dragon blow " + capitalize(target->query_name()) + " in the knee!\n");
      tell_object(target, capitalize(this_player()->query_name()) +
        " screams 'kiaa' and punches you in the knee!\n");
      say(capitalize(this_player()->query_name()) + " screams 'kiaa' and punches "+
        capitalize(target->query_name()) + " in the knee!\n", target);
    } else {
      tell_object(ob, "Your powerful dragon blow hits on "+capitalize(target->query_name())+
        "'s face making "+capitalize(target->query_name())+"'s nose to bleed!\n");
      tell_object(target, this_player()->query_name()+
        " powerfully punches you in the face!\n");
      say(capitalize(this_player()->query_name()) + " punches "+
        capitalize(target->query_name()) + " in the face!\n", target);
    }
if(dama > 175)  { dama=210;  } {
 tell_object(ob, "You focus all your strength and PUNCH " + capitalize(target->query_name()) + " in the stomach!\n");
      tell_object(target, capitalize(this_player()->query_name()) +
        " focuses all his strength and PUNCHES you in the stomach!\n");
      say(capitalize(this_player()->query_name()) + " focuses and PUNCHES "+
        capitalize(target->query_name()) + " in the stomach!\n", target);
}

    if(this_player()->query_attack() != target) this_player()->attack_object(target);
    target->hit_with_spell(dama, "physical");
}
}

fail_skill(str, ob) {
    object target;
    if(!ob)ob=this_player();
    if(!str) {
        tell_object(ob, "Use dragon blow at who?\n");
        return 1;
    }
    if(random(100) < this_player()->query_skills("dragon blow")) {
        resolve_skill(str);
        return 1;
    }
    target = present(str, environment(this_player()));
    if (!target) { write("You fail the skill.\n"); return; }
    tell_object(ob, "You try to punch " + target->query_name() + ", but miss.\n");
    tell_object(target, this_player()->query_name() + " tries to PUNCH you, but misses.\n");
    say(capitalize(this_player()->query_name()) + " tries to punch " + target->query_name() +
       ", but misses.\n", target);
    target->attack_object(this_player());
    this_player()->attack_object(target);
}

