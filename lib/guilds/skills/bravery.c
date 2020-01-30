int percent;
get_time(str) {
  return 14;
}
ep_cost() { return 10; }
query_type() { return "defensive"; }

get_arg() { return 1; }

resolve_skill(target) {
  if (this_player()->query_bravery()) {
	write("You are already using this skill.\n");
	return 1;
  }
  percent = 100;
  if (target) sscanf(target, "%d", percent);
  if (percent != 100) { write("You use only a part of your skill.\n"); }

  clone_object("/guilds/skill_obj/bravery_ob")->start(this_player(),percent);
  write("You prepare yourself for combat. You feel brave.\n");
  say(this_player()->query_name()+" looks braver.\n");
  return 1;
}

fail_skill() {
  write("As you think about the combat, you become afraid of death.\n");
  say(this_player()->query_name()+" shiver.\n");
  return 1;
}
