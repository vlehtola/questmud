#define SCROLL_D "/guilds/mage/objects/scroll_daemon"
#define SP_COST 100

get_time() {
    return 3;
}
query_type() { return "neutral"; }
ep_cost() { return 1; }

resolve_skill(target) {
	string tmp,word,tavu;
	object scroll;
    if(!target) { write("Usage: use scribble at scroll <syllabe>\n"); return 1; }
    if(sscanf(target, "%s %s", tmp, word) != 2) {
    write("Usage: use scribble at scroll <word>\n");
    return 1;
    }
    scroll = present(tmp, this_player());
    if(!scroll) { write("You don't have a scroll.\n"); return 1; }

// file modified by Celtron 09.04.2004
    if(!scroll->query_scroll()) { write("The scroll is not suitable for scribbling.\n"); return 1; }

    if(this_player()->query_sp() < SP_COST) { write("You don't have enough spell points.\n"); return 1; }
    this_player()->reduce_sp(SP_COST);

    tavu = lower_case(word);
// offensive spells in scrolls are not permitted. ++Celtron
    if(tavu == "blt" || tavu == "strm") {
      write("As you scribble the words, the scroll starts to glow and bursts in flames burning quickly into ashes!\n");
      tell_room(environment(this_player()), this_player()->query_name()+" tosses a burning scroll away!\n", ({ this_player(), }) );
      SCROLL_D->reduce_maker(this_player()->query_name());
      destruct(scroll);
      return 1;
    }
    scroll->add_new_syllabe(tavu);
    return 1;
}

fail_skill(target) {
    write("You fail the skill.\n");
    say(capitalize(this_player()->query_name()) + " fails the skill.\n");
}
