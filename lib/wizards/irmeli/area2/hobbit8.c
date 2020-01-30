inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_name", "hobbit");
    call_other(this_object(), "set_alias", "hobbit");
    call_other(this_object(), "set_short", "A big and strong hobbit operating the winch");
    call_other(this_object(), "set_long", "A big and strong hobbit is operating the winch. He is not similar like\n" +
                                          "the regular hobbits. He looks really powerful and mean. You might wonder\n" +
                                          "if he has something to do with the lift.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_race("hobbit");
    set_gender(1);
    set_block_dir();
    set_experience(query_exp() / 2);

}



