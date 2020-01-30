inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 69);
    call_other(this_object(), "set_name", "mariah");
    call_other(this_object(), "set_alias", "hani");
    call_other(this_object(), "set_short", "Mariah Carey sings Honey for Walla");
    call_other(this_object(), "set_long", "Mariah is (one of) Wallas hani(s).\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
}
