query_type() { return "witchcraft"; }

get_time() {
    return 14-(this_player()->query_skills("speedcrafting")/12);
}

ep_cost() { return 15-(this_player()->query_skills("speedcrafting")/20); }

resolve_skill() {
    object ob;
    int i;
    i = this_player()->query_skills("summon cauldron");
    write("You summon a magical cauldron.\n");
    say(capitalize(this_player()->query_name()) + " summons an magical cauldron.\n");
    ob = clone_object("/guilds/witch/obj/cauldron");
    move_object(ob, environment(this_player()));
    ob->set_owner(this_player()->query_name(), i);
}

fail_skill() {
        write("You fail the skill.\n");
        say(this_player()->query_name()+" fails the skill.\n");
}
