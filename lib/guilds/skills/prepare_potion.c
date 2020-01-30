query_type() { return "witchcraft"; }

get_time() {
    return 10-(this_player()->query_skills("speedcrafting")/12);
}
ep_cost() { return 10-(this_player()->query_skills("speedcrafting")/20); }


resolve_skill(tgt) {
        object potion;
        if(!tgt) {
                write("Use prepare potion at what?\n");
                return 1;
        }
        potion = present(tgt,this_player());
        if(!potion) {
                write("prepare what potion?\n");
                return 1;
                }
        if(!potion->query_potion()) {
                write("This skill only works on potions.\n");
                return 1;
        }
        if(potion->query_prepared()) {
                write("That potion is already prepared.\n");
                return 1;
        }
        if(!potion->query_full()) {
                write("Prepare an empty potion?\n");
                return 1;
        }
        write("You prepare the potion.\n");
        say(this_player()->query_name()+" prepares the potion.\n");
        potion->set_prepared();
return 1;
}

fail_skill() {
    write("You fail to prepare the potion.\n");
    say(capitalize(this_player()->query_name()) + " fails to prepare the potion.\n");
}

