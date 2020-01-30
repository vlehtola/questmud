query_type() { return "witchcraft"; }

get_time() {
    return 10-(this_player()->query_skills("speedcrafting")/12);
}
ep_cost() { return 10-(this_player()->query_skills("speedcrafting")/20); }

resolve_skill(tgt) {
        object herb;
        if(!tgt) {
                write("Use identify herb at what?\n");
                return 1;
        }
        herb = present(tgt, environment(this_player()));
        if(!herb) herb = present(tgt, this_player());
        if(!herb) {
                write("Ident�fy what herb?\n");
                return 1;
                }
        if(!herb->query_herb()) { write("You can only identify herbs with this skill.\n"); return 1; }
        if(this_player()->query_skills("identify herb") < random(110)) { write("You can't make any sense from "+herb->query_name()+".\n"); return 1; }
        write("The "+herb->query_name()+" glows a little as you identify it.\n");
        say(this_player()->query_name()+" identify's the herb.\n");
        write(herb->short()+".\n");
        write("The herb is "+call_other("/guilds/witch/obj/potion_d", "get_quality", herb->query_quality())+" quality.\n");
        herb->set_identify(1);
return 1;
}

fail_skill() {
    write("You fail to identify the herb.\n");
    say(capitalize(this_player()->query_name()) + " fails to identify herb.\n");
}

