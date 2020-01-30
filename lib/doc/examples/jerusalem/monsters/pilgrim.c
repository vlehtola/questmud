inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "Pilgrim");
    call_other(this_object(), "set_alias", "pilgrim");
    call_other(this_object(), "set_short", "A traveling pilgrim");
    call_other(this_object(), "set_long", "A bearded pilgrim, traveling the streets of Jerusalem.\n");
    call_other(this_object(), "set_al", 1);
    call_other(this_object(), "set_aggressive", 0);
    set_gender(1);
    
}
