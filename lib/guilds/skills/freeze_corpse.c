int ep_cost() { return 5; }

get_time() {
    return 5;
}
query_type() { return "neutral"; }

/* freeze corpse */
resolve_skill(str) {
	object ob;
	object halt;
	int i;
	int time;
	if(!str) { write("use at what?\n"); return 1; }
	ob = present(str, environment(this_player()));
	if(!ob) { write(str+" is not valid target.\n"); return 1; }
	if(!ob->query_corpse()) { write("This skill works only at corpses.\n"); return 1; }
        if(ob->query_freeze_shadow()) {
	  write("It is already frozen.\n");
	  return 1;
	}
	write("You prevent the corpse from decaying.\n");
	say(this_player()->query_name()+" prevents the corpse from decaying.\n");
	halt = clone_object("/guilds/skill_obj/freeze_shadow");
	time = this_player()->query_int()*5+this_player()->query_wis()*5;
	halt->start(ob,time);
  return 1;
}

fail_skill() {
  write("You fail to freeze the corpse.\n");
  say(this_player()->query_name()+" fails to freeze the corpse.\n");
  return 1;
}
