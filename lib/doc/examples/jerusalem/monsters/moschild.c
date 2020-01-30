inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_race("human");
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "child");
    call_other(this_object(), "set_alias", "child");
    call_other(this_object(), "set_short", "A Moslem child carrying vedgetables");
    call_other(this_object(), "set_long", "A Moslem child taking a basket of vedgetables to a store.\n");
    call_other(this_object(), "set_al", 5);
    call_other(this_object(), "set_aggressive", 0);

}
