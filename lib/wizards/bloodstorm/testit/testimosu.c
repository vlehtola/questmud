inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "mosu");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "Pikku mosu");
    call_other(this_object(), "set_long", "pikkupikku mosu joka on todellinen testi m��bsteri. T��ll� se\n"+
                                          "sipsuttelee edes takaisin ja v�h�n muuallekkin, juuri t�lleens�\n"+
                                          "dumdiduu\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);
 

}
