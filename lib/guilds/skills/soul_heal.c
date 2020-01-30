#define SP_COST 80
get_time() {
  return random(3)+2;
}
query_type() { return "neutral"; }
ep_cost() { return 1; }

resolve_skill(str) {
    object target;
    int effect;
    if(!str) {
                write("Use soul heal at what?\n");
                return 1;
        }
        if(this_player()->query_attack()) {
                write("You can't use soul heal in combat.\n");
                return 1;
        }
        target = present(str, environment(this_player()));
        if(!target || !living(target)) {
         write(capitalize(str)+" is not a valid target.\n");
         return 1;
    }
    if(target != this_player()) { write("You can only use this skill on yourself.\n"); return 1; }

    if ( target->query_sp() < SP_COST ) {
      write("You lack the magical power to use this skill.\n");
      return 1;
    }

    effect = (this_player()->query_skills("soul heal")*2);
    write("You use some your mana to heal your soul\n");
    say(this_player()->query_name()+" glows brightly.\n");
    target->heal_hp(effect);
        this_player()->reduce_sp(SP_COST);    
}
fail_skill(str) {
    write("You fail the skill.\n");
    say(this_player()->query_name()+" fails the skill.\n");
}

