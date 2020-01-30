inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "maid");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "Maid is here helping chef");
    call_other(this_object(), "set_long", "Cute looking maid is here washing potatoes and peeling some\n"+
                                          "carrots for todays dish. She is wearing a blue dress and white\n"+
                                          "apron and she looks very busy\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);
 
}
