inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 12);
    set_animal();
    call_other(this_object(), "set_name", "Rat");
    call_other(this_object(), "set_alias", "rat");
    call_other(this_object(), "set_short", "A slimy rat");
    call_other(this_object(), "set_long", "A slimy rat writhing in slime.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_animal(1);
    set_al_aggr(20);
}

