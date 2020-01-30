get_time(str) {
  return random(1)+4;
}
ep_cost() { return 2; }
query_type() { return "offensive"; }

resolve_skill(str) {
   int effect;
   object poison,target,tp;
   tp = this_player();
   effect = this_player()->query_skills("poison breath")/10;
   if(!str && this_player()->query_attack()) {
    str = lower_case(this_player()->query_attack()->query_name());
   }
   if(!str) {
           write("use poison at what?\n");
           return 1;
   }
    target = present(str, environment(this_player()));
    if(!target || !living(target)) {
    write(capitalize(str)+" is not a valid target.\n");
    return 1;
}

if(present("poison_ob", target)) { write(capitalize(target->query_name()) + " is allready poisoned.\n"); return 1; }

    write("You breath of poisonous cloud at "+ capitalize(target->query_name()) + ".\n");
    tell_object(target, tp->query_name()+" breathes a poisonous cloud in the air and you are immediately infected.\n");
    say(tp->query_name()+ " breath's a poisonous cloud in the air and "+capitalize(target->query_name()) + " is immediately infected.\n", target);
    poison = clone_object("/wizards/neophyte/poison_ob");
    move_object(poison, target);
    poison->start(target, effect);
    target->attack_object(tp);
}

fail_skill(str) {
        write("You fail to breath a poisonous cloud in the air.\n");
        say(this_player()->query_name()+" fails to breath of poisonous cloud in the air.\n");
}
