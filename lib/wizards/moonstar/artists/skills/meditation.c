#define MASTERY_D "/daemons/mastery_d"
object varjo;

get_time() {
    return 5;
}
query_type() { return "neutral"; }

resolve_skill(target) {
    int i;
    object ob;
    if (this_player()->query_attacker_ob()) {
        write("Can't use meditation while fighting.\n");
        return 0;
    }
    ob = all_inventory(environment(this_player()));
    while(i<sizeof(ob)) {
      if(ob[i] != this_player() && living(ob[i])) {
        write("You don't want to sit down and meditate while possible enemy is nearby.\n");
        return 0;
      }
      i += 1;
    }
    if(this_player()->query_focus_elements()) {
        write("You can't meditate while focusing!\n");
        return 1;
    }
    write("You sit down and start meditate with power of fire.\n");
    say(capitalize(this_player()->query_name()) + " sits down and starts to meditate.\n", this_player());
    i = 30+random(30) - (this_player()->query_con() / 4);
    if (i<20) { i = 20; }
    call_out("awake", i);
    varjo = clone_object("/guilds/skill_obj/meditation_ob");
    varjo->start(this_player());
}

fail_skill(target) {
    write("You try to start meditating, but elements distracts your concentration.\n");
    say(capitalize(this_player()->query_name()) + " tries to meditate, but loses " +this_player()->query_possessive()+" concentration.\n", this_player());
}

awake() {
  this_player()->heraa();
  write("You wake up and feel somewhat better.\n");
  say(capitalize(this_player()->query_name()) + " wakes up and looks a bit better.\n");
  this_player()->set_hp( ( this_player()->query_hp()*3 + this_player()->query_max_hp() ) / 4 + this_player()->query_skill("mastery of meditation") + MASTERY_D->mastery("Mastery of body focusing",this_player())*3);
  this_player()->set_ep( ( this_player()->query_ep()*2 + this_player()->query_max_ep() ) / 3 + this_player()->query_skill("mastery of meditation")/2);
}

