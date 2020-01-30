inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 3);
    call_other(this_object(), "set_name", "hobbit");
    call_other(this_object(), "set_alias", "slave");
    call_other(this_object(), "set_short", "A hobbit slave working here");
    call_other(this_object(), "set_long", "A hobbit slave is digging ground with small shovel. His clothes is\n" +
                                          "dirty from dust and his shirt is full of holes. He came to here\n" +
                                          "to earn money.\n");
    call_other(this_object(), "set_al", 10);
    set_race("hobbit");
    set_gender(1);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
    
}



