inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 10);
    call_other(this_object(), "set_name", "ant");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A huge ant guard");
    call_other(this_object(), "set_long", "This very large ant is guarding the queen, eyeing you wearily.\n" +
                                        "It has HUGE claws, which make you feel uneasy. You shiver from the\n" +
                                        "thought how easily they might tear you apart.\n");
    call_other(this_object(), "set_wc", 10);
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("east");
        set_animal(1);
}
