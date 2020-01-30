get_time() {
  return random(2)+5;
}
query_type() { return "offensive"; }
ep_cost() { return 10; }

resolve_skill(str) {
    int dama;
    object wepa,type,target, tp;
    tp = this_player();
        if (this_player()->query_right_weapon()) {
             if(!str && this_player()->query_attack()) {
                str = lower_case(this_player()->query_attack()->query_name());
             }
        wepa = this_player()->query_right_weapon();
        type = wepa->query_sub_type();
        dama = this_player()->query_str() + this_player()->query_dex() / 2;
        dama += wepa->query_wc();
        if(type == "dagger") {
     if (!str) {
        write("Use stab at whom?\n");
        return 1;
     }
     target = present(str, environment(this_player()));
     if(!target || !living(target) || target == this_player()) {
        write(capitalize(str)+" is not a valid target.\n");
        return 1;
     }
        if(dama > 600) { dama = 600; }
        call_other("/wizards/neophyte/stab_message","get_msg",target,tp);
        this_player()->attack_object(target, 1);
        target->hit_with_spell(dama, "physical");
        if(target) {
          if(this_player()->query_skills("double stab") > random(130)) {
                write("Before "+ target->query_name() + " can even scream, you quickly stab again plunging your weapon even deeper.\n");
                tell_object(target, "Before you can even scream, "+ this_player()->query_name() + " quickly stabs you again.\n");
                say("Before "+ target->query_name()+ " can even scream "+ this_player()->query_name() + " quickly stabs again.\n",target);
            dama = dama * this_player()->query_skills("double stab") / 200;
            if(dama > 300) dama = 300;
            target->hit_with_spell(dama, "physical");
         if(target) {
          if(this_player()->query_skills("stunning touch") > random(150)) {
                          write("As "+target->query_name()+ " writhes in pain from your last stab, you notice his balance fail and quickly stab again.\n");
                          say("As "+ target->query_name()+ " writhes in pain, "+ this_player()->query_name()+ " quickly stab again.\n",target);
                          tell_object(target, "As you writh in pain "+ this_player()->query_name()+ " quickly stab again.\n");
            target->set_stunned(random(2)+1);
            return 1;
          }
          write("1\n");
          return 1;
}
write("2\n");
return 1;
}
write("3.\n");
return 1;
}
write("4\n");
return 1;
}
write("You need a dagger to use this skill.\n");
return 1;
}
write("You need a dagger to use this skill.\n");
return 1;
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
