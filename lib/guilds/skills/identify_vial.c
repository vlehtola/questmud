query_type() { return "witchcraft"; }

get_time() {
    return 10-(this_player()->query_skills("speedcrafting")/12);
}
ep_cost() { return 10-(this_player()->query_skills("speedcrafting")/20); }


resolve_skill(tgt) {
        object vial;
        if(!tgt) {
                write("Use identify vial at what?\n");
                return 1;
        }
        vial = present(tgt, this_player());
        if(!vial) vial = present(tgt, environment(this_player()));
        if(!vial) {
                write("Ident�fy what vial?\n");
                return 1;
                }
        if(!function_exists("query_potion", vial)) { write("This skill works only vials.\n"); return 1; }
        write("You identify the vial.\n");
        say(this_player()->query_name()+" identify's the vial.\n");
        vial->identify_vial();
return 1;
}

fail_skill() {
    write("You fail to identify the vial.\n");
    say(capitalize(this_player()->query_name()) + " fails to identify vial\n");
}

