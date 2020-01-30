inherit "obj/monster"; 
 
reset(arg) {
    object glasseye;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "man");
    call_other(this_object(), "set_alias", "supervisor");
    call_other(this_object(), "set_short", "The ferry supervisor of OilOhnRock, sleeping on his bunk");
    call_other(this_object(), "set_long", "The man sleeps tight and doesn't seem to be disturbed\n" +
                                          "by the fact that you have entered his quarters.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
 
     
    glasseye=clone_object("/wizards/walla/peepseye/eq/objs/eye");
    move_object(glasseye, this_object());
 }
