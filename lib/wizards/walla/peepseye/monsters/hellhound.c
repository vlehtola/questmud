inherit "obj/monster"; 
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "hellhound");
    call_other(this_object(), "set_alias", "vorticon");
    call_other(this_object(), "set_short", "A Vorticon hellhound");
    call_other(this_object(), "set_long", "This hound is about the size of a wolf, except that it is coal black,\n" +
                                          "and it's eyes are blood red. You see some kind of smoke coming out of the animals\n" +
                                          "nostrils and foam out of it's mouth.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 1);

 
}
 
