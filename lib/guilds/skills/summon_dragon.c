int ep_cost() { return 50; }

get_time() {
    return 15;
}
query_type() { return "neutral"; }

resolve_skill() {
        object ob;
         if(present("dragon",environment(this_player()))) { write("You already have one!\n"); return 1; }
        write("You summon dragon.\n");
    say(capitalize(this_player()->query_name()) + " summons dragon.\n");
    ob = clone_object("/wizards/garath/dragonists/dragon");
    move_object(ob, environment(this_player()));
    ob->set_owner(this_player()->query_name());
    if(this_player()->query_skill("Knowledge of Dragon") >= 10) {
      ob->set_dlvl((int)this_player()->query_skill("Knowledge of Dragon")/10);
      ob->set_dsoul(50000);
    }
}

fail_skill() {
        write("You fail to summon dragon.\n");
    say(capitalize(this_player()->query_name()) + " fails to summon dragon.\n");
}