inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 60);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "King's personal bodyguard");
    call_other(this_object(), "set_long", "Highly ranked guard who seems to be very strong and he is\n"+
                                          "giving mean looks to everyone who tries to approach the\n"+
                                          "king. He is not wearing any visible armours or weapons,\n"+
                                          "but he may have something in his pockets.\n");
    call_other(this_object(), "set_al", 10); 
    call_other(this_object(), "set_aggressive", 0);
     
}
