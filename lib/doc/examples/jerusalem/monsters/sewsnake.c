inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 19);
    set_animal();
    call_other(this_object(), "set_name", "Snake");
    call_other(this_object(), "set_alias", "snake");
    call_other(this_object(), "set_short", "A brown snake");
    call_other(this_object(), "set_long", "A brown snake covered in sewage.\n");
    call_other(this_object(), "set_al", -5);
    call_other(this_object(), "set_aggressive", 1);
    set_animal(1);
    set_al_aggr(10);
}
