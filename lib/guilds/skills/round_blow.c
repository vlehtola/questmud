get_time() {
    return 6;
}
ep_cost() { return 15; }
query_type() { return "offensive"; }

resolve_skill() {
  object skill, skilli, ob;
  if (this_player()->query_name_of_right_weapon()) {
    if(present("round blow object", this_player())) {
        write("You are already prepared to perform the round blow maneuver.\n");
        return 1;
    }
    write("You are ready to perform round blow.\n");
    ob = clone_object("/guilds/skill_obj/round_blow_object");
    move_object(ob, this_player());
    ob->start(this_player());
    return 1;
  }
  write("You need a weapon to perform this skill.\n");
  return 1;
}

fail_skill() {
    write("You fail the skill.\n");
    return 1;
}
