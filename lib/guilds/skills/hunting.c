get_time() {
    return 9;
}
ep_cost() { return 5; }
query_type() { return "neutral"; }

resolve_skill(target) {
    object victim;
    write("You sneak in the nearby wilderness and find a good animal to eat.\n");
    say(capitalize(this_player()->query_name()) + " suddenly disappears to the wilderness and comes back with some food.\n", this_player());
    victim = clone_object("/guilds/skill_obj/victim");
    move_object(victim,this_player());
}

fail_skill(target) {
    write("You fail to find any good animals to eat.\n");
    say(capitalize(this_player()->query_name()) + " stumbles somewhere making loud noises and comes back with a disappointed look on " + this_player()->query_possessive() + " face.\n", this_player());
}
