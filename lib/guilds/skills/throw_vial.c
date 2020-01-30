query_type() { return "witchcraft"; }

get_time() {
    return 25-(this_player()->query_skills("speedcrafting")/5);
}
ep_cost() { return 25-(this_player()->query_skills("speedcrafting")/5); }

resolve_skill(str) {
        object vial,target,effect;
        int i;
        string tmp;

        i = this_player()->query_skills("herbalist knowledge")/10;
        if(this_player()->query_attack()) {
        write("This skill don't work in battle.\n"); return 1;
    }
        if(!str) { write("Use throw vial at what?\n"); return 1; }
        target = present(str, environment(this_player()));
        if(!target || !living(target) || target == this_player()) { write(str+" is not a valid target.\n"); return 1; }
        vial = present("vial", this_player());
        if(!vial) { write("You don't have a vial to throw.\n"); return 1; }
        if(!vial->query_potion()) { write("Only vials can be thrown.\n"); return 1; }
        if(!vial->query_prepared()) { write("But the vial is not prepared.\n"); return 1; }
        if(!vial->query_full()) { write("Throw an empty potion?\n"); return 1; }
        if(call_other("/guilds/witch/obj/potion_d", "can_drink", vial->query_effect()) == 0) {
                write("This vial cannot be thrown.\n");
                        return 1;
                }

        tmp = vial->query_effect();
        if(!tmp) { write("ERROR\n"); return 1; }
        effect = clone_object("/guilds/witch/potions/"+tmp+".c");
        destruct(vial);
        write("You throw the vial at "+target->query_name()+".\n");
        say(this_player()->query_name()+" throws an vial at "+target->query_name()+".\n");
        effect->start(i+1, target);
        target->attack_object(this_player());
return 1;
}
fail_skill() {
    write("You fail to throw the vial.\n");
    say(capitalize(this_player()->query_name()) + " fails to throw the vial.\n");
}

