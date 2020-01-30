inherit "obj/monster"; 
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("human");
    call_other(this_object(), "set_level", 11);
    call_other(this_object(), "set_name", "citizen");
    call_other(this_object(), "set_alias", "citizen");
    call_other(this_object(), "set_short", "A peaceful citizen of Jericho");
    call_other(this_object(), "set_long", "This citizen looks strangely at you.\n" +
                                          "Maybe he hasn't seen too many wierdoes like you before.\n" +
                                          "Leave the poor guy alone.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
 
}
