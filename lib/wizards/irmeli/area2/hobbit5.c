inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 2);
    call_other(this_object(), "set_name", "hobbit");
    call_other(this_object(), "set_alias", "assistant");
    call_other(this_object(), "set_short", "A hobbit assistant");
    call_other(this_object(), "set_long", "A hobbit assistant has hired  to help chef with his job. Assistant\n" +
                                          "looks very sad and tired. She has lifted more boxes than you have\n" +
                                          "ever seen.\n");
    call_other(this_object(), "set_al", 10);
    set_race("hobbit");
    set_gender(2);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
    
}



