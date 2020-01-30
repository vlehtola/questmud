inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 16);
    set_animal();
    call_other(this_object(), "set_name", "Eel");
    call_other(this_object(), "set_alias", "eel");
    call_other(this_object(), "set_short", "A long eel");
    call_other(this_object(), "set_long", "A long slimy eel, sucking your blood this very minute.\n");
    call_other(this_object(), "set_al", -5);
    call_other(this_object(), "set_aggressive", 1);
    set_animal(1);
    set_al_aggr(10);
}
