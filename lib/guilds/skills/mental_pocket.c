
get_time(str) {
  return random(3)+2;
}
ep_cost() { return 6; }
query_type() { return "neutral"; }

resolve_skill(str) {
	int i;
	object ob;
    if(this_player()->query_sp() < 100) {
    write("You don't have enough mental powers to use this skill.\n");
	return 1;
}
if(present("void pocket", this_player())) {
write("You already have void pocket.\n");
return 1;
}
write("You create void pocket.\n");
say(this_player()->query_name()+" creates a mental pocket.\n");
i = this_player()->query_skills("mental pocket")+this_player()->query_wis()+this_player()->query_int()+this_player()->query_level()*1000;
if(i>10000)i=10000;
ob = clone_object("/guilds/psi/specials/void_pocket");
move_object(ob, this_player());
ob->set_max_weight(i);

}

fail_skill(str) {
write("You fail the skill.\n");
say(this_player()->query_name()+" fails the skill.\n");
}
