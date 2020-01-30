#define SP_COST 350
#define SCROLL_D "/guilds/mage/objects/scroll_daemon"
get_time() {
    return 6;
}
query_type() { return "neutral"; }

ep_cost() { return 1; }

resolve_skill(str) {
	object scroll;
	if(this_player()->query_sp() < SP_COST) { write("You don't have enough spell points to create scroll.\n"); return 1; }
	if(SCROLL_D->query_maker(this_player()->query_name()) > 9) { write("You can't create anymore scrolls.\n"); return 1; }
    write("You create a empty scroll.\n");
    say(this_player()->query_name()+" creates an empty scroll.\n");
    scroll = clone_object("/guilds/mage/objects/scroll");
    move_object(scroll, this_player());
    this_player()->reduce_sp(SP_COST);
    SCROLL_D->add_maker(this_player()->query_name());
    scroll->set_owner(this_player()->query_name());
    return 1;
}

fail_skill(target) {
    write("You fail to create a empty scrolls.\n");
    say(capitalize(this_player()->query_name()) + " fails to create an empty scroll.\n");
}
