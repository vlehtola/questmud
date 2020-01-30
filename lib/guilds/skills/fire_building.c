get_time() {
    return 7;
}

ep_cost() {
  return 10;
}
query_type() { return "neutral"; }

resolve_skill(target, object who) {
    object ob;
    if(!who)who=this_player();
    if(present("campfire",environment(who))) {
      tell_object(who,"Here is a campfire already.\n");
      return 1;
    }
  if(environment(who)->query_water()) {
    tell_object(who, "You can't build a fire on water.\n");
    return 1;
  }
    tell_object(who, "You find materials for your fire and light it.\n");
    tell_room(environment(who), capitalize(who->query_name()) + " builds a warm campfire.\n", ({ who, }));
    ob = clone_object("/guilds/skill_obj/fire");
    move_object(ob, environment(who));
    call_other(ob, "warm");
    //Rag was here 12.7.04
    ob->set_bonus(who->query_skills("fire building"));
    return 1;
}

fail_skill(target) {
    write("You fail to find any good materials for your fire.\n");
    say(capitalize(this_player()->query_name()) + " searches sticks, but can't find them enough for " + this_player()->query_possessive() + " purpose.\n", this_player());
    return 1;
}
