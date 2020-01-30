inherit "obj/monster";   
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("babe");
    set_gender(2);
    call_other(this_object(), "set_level", 69);
    call_other(this_object(), "set_name", "victoria");
    call_other(this_object(), "set_alias", "posh");
    call_other(this_object(), "set_short", "Victoria Adams, a.k.a. Posh Spice.");
    call_other(this_object(), "set_long", "Victoria sits in her chair, 'naked'.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
}

 
