inherit "obj/monster"; 
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("rabbit");
    call_other(this_object(), "set_level", 2);
    call_other(this_object(), "set_name", "rabbit");
    call_other(this_object(), "set_alias", "rabbit");
    call_other(this_object(), "set_short", "A cute little rabbit");
    call_other(this_object(), "set_long", "A cute little rabbit sits here looking at you happily.\n" +
                                          "It has looks very cute.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
 
 
 
}
