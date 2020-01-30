inherit "obj/monster";

reset(arg) {
    object boulder;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 2);
    call_other(this_object(), "set_name", "ant");
    call_other(this_object(), "set_alias", "worker");
    call_other(this_object(), "set_short", "A red giant ant worker");
    call_other(this_object(), "set_long", "This human sized ant is carrying large rocks on its back,\n" +
                                          "but does not even look exhausted. Is seems that it is\n" +
                                          "completely ignoring you.\n");
    call_other(this_object(), "set_wc", 4);
    call_other(this_object(), "set_ac", 0);
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
        set_animal(1);
}
