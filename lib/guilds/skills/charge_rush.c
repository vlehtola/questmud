get_time() {
    return 2;
}

ep_cost() {
    return 45;
}
query_type() { return "offensive"; }

resolve_skill(string str) {
  if(this_player()->query_charge_ob()) {
    write("You are already charging.\n");
    return 1;
  }
  if(!str) {
    write("Charge where?\n");
    return 1;
  }
  if(str != "north" && str != "south" && str != "west" && str != "east" && str != "northwest"
      && str != "northeast" && str != "southeast" && str != "southwest") {
    write("You are unable to charge that way.\n");
    return 1;
  }
  if(!this_player()->query_berserk()) {
    write("You must be in berserk to use this skill.\n");
    return 1;
  }
  if(!environment(this_player())->query_valid_dir(str)) {
    write("No such direction.\n");
    return 1;
  }
  clone_object("/guilds/skill_obj/charge_ob")->start(this_player(),str);
}

fail_skill() {
  write("You fail the skill.\n");
  say(this_player()->query_name()+" fails in "+this_player()->query_possessive()+" charge.\n");
  return 1;
}
