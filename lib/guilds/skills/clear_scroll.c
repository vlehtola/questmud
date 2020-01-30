#define SCROLL_D "/guilds/mage/objects/scroll_daemon"
get_time() {
    return 1;
}
query_type() { return "neutral"; }
ep_cost() { return 1; }

resolve_skill(target) {
	string tmp,word,tavu;
	object scroll;
    if(!target) { write("Cast at what?\n"); return 1; }
    scroll = present(target, this_player());
    if(!scroll) scroll = present(target,environment(this_player()));
    if(!scroll) {
	write("You don't have a such thing.\n"); return 1; }
    if(!scroll->query_scroll()) { write("This scroll works only at scrolls.\n"); return 1; }
    if(scroll->query_owner() != this_player()->query_name()) { write("This scroll is not yours.\n"); return 1; }

    SCROLL_D->reduce_maker(this_player()->query_name());
    destruct(scroll);
    write("You destroy the scroll.\n");
    say(this_player()->query_name()+" destroys one of the scrolls.\n");
    return 1;
}

fail_skill(target) {
    write("You fail the skill.\n");
    say(capitalize(this_player()->query_name()) + " fails the skill.\n");
}
