inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "mosu");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "Pikku mosu");
    call_other(this_object(), "set_long", "pikkupikku mosu joka on todellinen testi mööbsteri. Täällä se\n"+
                                          "sipsuttelee edes takaisin ja vähän muuallekkin, juuri tälleensä\n"+
                                          "dumdiduu\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);
 

}
