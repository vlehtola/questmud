inherit "obj/monster"; 
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 19);
    call_other(this_object(), "set_name", "secretary");
    call_other(this_object(), "set_alias", "chick");
    call_other(this_object(), "set_short", "The beautiful secretary of the mayor");
    call_other(this_object(), "set_long", "The secretary has seen a lot of men in her\n" +
                                          "early days as secretary. Now however she has\n" +
                                          "dedicated her services to the mayor.\n");
    call_other(this_object(), "set_al", 100);
    call_other(this_object(), "set_aggressive", 0);
 
 
}

