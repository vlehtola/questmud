query_type() { return "witchcraft"; }
get_time() {
    return 14-(this_player()->query_skills("speedcrafting")/12);
}
ep_cost() { return 15-(this_player()->query_skills("speedcrafting")/20); }

resolve_skill(target) {
    object ob;
    int i;
    i = this_player()->query_skills("create vial");
    ob = clone_object("/guilds/witch/obj/empty_potion");
    ob->set_size(i);
    move_object(ob, this_player());
    write("You create empty vial.\n");
    say(this_player()->query_name()+" creates a empty vial.\n");
}

fail_skill(target) {
        write("You fail to create empty vial.\n");
        say(this_player()->query_name()+" fails to create empty vial.\n");
}

