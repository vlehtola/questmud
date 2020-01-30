object varjo;

get_time() {
    return 5;
}
query_type() { return "neutral"; }

resolve_skill(target) {
    int i;
    object ob;
    if (this_player()->query_attacker_ob()) {
        write("Can't meditate while fighting.\n");
        return 0;
    }
    ob = all_inventory(environment(this_player()));
    while(i<sizeof(ob)) { 

      if(ob[i] != this_player() && living(ob[i])) {
        write("You are unable to concentrate while a possible enemy is nearby.\n");
        return 0;
      }
      i += 1;
    }
  if(environment(this_player())->query_water()) {
    write("You can't meditate in water.\n");
    return 1;
  }
    if(this_player()->query_berserk()) {
        write("You can't meditate while raging!\n");
        return 1;
    }
    write("You start meditating.\n");
    say(capitalize(this_player()->query_name()) + " starts to meditate.\n", this_player());
    i = 30+random(30) - (this_player()->query_int() / 4);
    if (i<20) { i = 20; }
    call_out("awake", i);
    varjo = clone_object("/guilds/skill_obj/meditate_ob");
    varjo->start(this_player());
}

fail_skill(target) {
    write("You fail to concentrate and fail to start meditating.\n");
    say(capitalize(this_player()->query_name()) + " tries to meditate, but fails with angry look on " + this_player()->query_possessive() + " face.\n", this_player());
}

awake() {
  this_player()->heraa();
  write("You wake up and feel mentally relaxed.\n");
  say(capitalize(this_player()->query_name()) + " wakes up and looks mentally relaxed.\n");
  this_player()->set_sp( ( this_player()->query_sp()*2 + this_player()->query_max_sp() ) / 3);
  this_player()->set_hp( ( this_player()->query_hp()*9 + this_player()->query_max_hp() ) / 10);
}
