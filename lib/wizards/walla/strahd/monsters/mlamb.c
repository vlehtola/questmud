inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 8);
    call_other(this_object(), "set_name", "lamb");
    call_other(this_object(), "set_alias", "lamb");
    call_other(this_object(), "set_short", "A strange, mutated lamb, nagging the grass");
    call_other(this_object(), "set_long", "The lamb eats some grass but seems to stay\n"+
"away from \n" +
                                          "the northern part of the pastuary.\n");
    call_other(this_object(), "set_wc", 3);
    call_other(this_object(), "set_ac", 0);
    call_other(this_object(), "set_al", 00);
    call_other(this_object(), "set_aggressive", 0);
 
}
