ep_cost() { return 100; }

get_time() {
    return 15;
}

resolve_skill() {
        object ob;
         if(present("bear",environment(this_player()))) { write("You already have one!\n"); return 1; }
        write("You summon bear.\n");
    say(capitalize(this_player()->query_name()) + " summons bear.\n");
    ob = clone_object("/wizards/yodin/animals/bear");
    move_object(ob, environment(this_player()));
    ob->set_owner(this_player()->query_name());
    if(this_player()->query_skill("Knowledge of animals") >= 10) {
      ob->set_dlvl((int)this_player()->query_skill("Knowledge of animals")/10);
      ob->set_dsoul(50000);
    }
}

fail_skill() {
        write("You fail to summon .\n");
    say(capitalize(this_player()->query_name()) + " fails to summon bear.\n");
}
