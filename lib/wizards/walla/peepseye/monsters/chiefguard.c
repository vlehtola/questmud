 inherit "obj/monster";               
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 18);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "vorticon");
    call_other(this_object(), "set_short", "A Vorticon guard");
    call_other(this_object(), "set_long", "The guard looks like a sort of bear that stands on \n" +
                                          "its back feet. It doesn't seem to be wearing any clothes but it still \n" +
                                          "has somekind of natural armour on itself. The animal stands \n" +
                                          "about 7 feet tall towards you and makes strange noises.\n");
    call_other(this_object(), "set_al", -21);
    call_other(this_object(), "set_aggressive", 1);
 
}
 
