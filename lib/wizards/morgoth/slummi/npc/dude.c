inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 5);
    call_other(this_object(), "set_name", "dude");
    call_other(this_object(), "set_alias", "dude");
    call_other(this_object(), "set_short", "A nasty looking dude");
    call_other(this_object(), "set_long",
    "This old punk is here picking up a fight.\n");
    call_other(this_object(), "set_al", -15);
    call_other(this_object(), "set_race", "human");
    call_other(this_object(), "set_aggressive", 1);
 
}
