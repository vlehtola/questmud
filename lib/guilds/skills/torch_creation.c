get_time() {
    return 10;
}
ep_cost() { return 2; }
query_type() { return "neutral"; }

resolve_skill(target, ob) {
    object who;
        object torch;
	who=ob;
	if(!who)who=this_player();
    tell_object(who, "You find sticks and other materials to your torch and tie them together.\n");
    tell_room(environment(who), capitalize(who->query_name()) + " makes a torch from some sticks.\n", ({ who, }));
    torch = clone_object("/world/eq/torch");
    move_object(torch,who);
}

fail_skill(target, ob) {
	object who;
	who=ob;
	if(!who)who=this_player();
    tell_object(who, "You fail to find any good materials for your torch.\n");
    tell_room(environment(who), capitalize(who->query_name()) + " searches sticks, but can't find them enough for a torch.\n", ({ who, }));
}
