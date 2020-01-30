object varjo;

get_time() {
    return 5;
}
query_type() { return "neutral"; }

resolve_skill(target) {
    int i;
    object ob;
    if (this_player()->query_attacker_ob()) {
        write("Can't sleep while fighting.\n");
        return 0;
    }
    ob = all_inventory(environment(this_player()));
    while(i<sizeof(ob)) {
      if(ob[i] != this_player() && living(ob[i])) {
        write("You don't want to sleep while possible enemy is nearby.\n");
        return 0;
      }
      i += 1;
    }
  if(environment(this_player())->query_water()) {
    write("You can't build a camp on water.\n");
    return 1;
  }
    if(this_player()->query_berserk()) {
        write("You can't sleep while raging!\n");
        return 1;
    }
    write("You fall asleep.\n");
    say(capitalize(this_player()->query_name()) + " starts to sleep.\n", this_player());
    i = 30+random(30) - (this_player()->query_con() / 4);
    if (i<20) { i = 20; }
    call_out("awake", i);
    varjo = clone_object("/guilds/skill_obj/camping_ob");
    varjo->start(this_player());
}

fail_skill(target) {
    write("You try to get some sleep, but sounds around you keep you awake.\n");
    say(capitalize(this_player()->query_name()) + " tries to sleep, but wakes up with angry look on " +
this_player()->query_possessive() + " face.\n", this_player());
}

awake() {
  this_player()->heraa();
  write("You wake up and feel somewhat better.\n");
  say(capitalize(this_player()->query_name()) + " wakes up and looks a bit better.\n");

  this_player()->set_hp( ( this_player()->query_hp()*4 + this_player()->query_max_hp() ) / 4 + 100);
  this_player()->set_ep( ( this_player()->query_ep()*2 + this_player()->query_max_ep() ) / 3);
}
