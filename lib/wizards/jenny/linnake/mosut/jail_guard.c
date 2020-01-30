inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 37);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "Jail guard is here keeping an eye on prisoners");
    call_other(this_object(), "set_long", "This jail guard looks pretty muscular and he has many\n"+
                                          "scars on his face and arms. He looks pretty mean and he\n"+
                                          "surely doesn't take good care of any prisoners here.\n");
    call_other(this_object(), "set_al", -3);
    call_other(this_object(), "set_aggressive", 0);
    set_gender(1); 
}
