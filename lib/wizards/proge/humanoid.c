inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 13);
    call_other(this_object(), "set_name", "human");
    call_other(this_object(), "set_short", "human");
    call_other(this_object(), "set_long",
"just humanoid.\n");
    call_other(this_object(), "set_al", -8);
    call_other(this_object(), "set_aggressive", 0);
    call_other(this_object(), "set_race", "human");
}
