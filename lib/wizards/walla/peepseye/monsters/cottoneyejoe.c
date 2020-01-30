inherit "obj/monster"; 
 
reset(arg) {
    object glasseye;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 37);
    call_other(this_object(), "set_name", "pirate");
    call_other(this_object(), "set_alias", "joe");
    call_other(this_object(), "set_short", "Cotton-Eye Joe");
    call_other(this_object(), "set_long", "Cotton-Eye is a big man, he has all the characteristiques of a pirate.\n" +
                                          "He is grumpy, mean, and not attractive.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
 
    glasseye=clone_object("/wizards/walla/peepseye/eq/objs/eye");
    move_object(glasseye, this_object());
 }


