query_type() { return "witchcraft"; }

get_time() {
    return 20-(this_player()->query_skills("speedcrafting")/6);
}
ep_cost() { return 20-(this_player()->query_skills("speedcrafting")/7); }


resolve_skill(str) {
    object ob,vial;
    if(!str) { write("You need to target this skill at vial.\n"); return 1; }
    vial = present(str, this_player());
    if(!vial) { write("You don't have such thing.\n"); return 1; }
        if(!vial->query_potion()) { write("This skill works only for vials.\n"); return 1; }
                if(vial->query_full() == 1) { write("This vial is not empty.\n"); return 1; }
    ob = present("cauldron", this_player());
    if(!ob) ob = present("cauldron", environment(this_player()));
    if(!ob) { write("You don't have cauldron.\n"); return 1; }
    if(ob->query_pot_owner() != this_player()->query_name()) { write("This cauldron is not yours.\n"); return 1; }
    write("You start to cooking the herbs.\n");
    say(this_player()->query_name()+" starts to cooking the herbs.\n");
    ob->make_potion(vial);
    return 1;
}

fail_skill() {
        write("You fail to make potion.\n");
        say(this_player()->query_name()+" fails to make potion.\n");
 return 1;
}
