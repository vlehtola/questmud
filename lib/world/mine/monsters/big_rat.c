inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_name", "rat");
    call_other(this_object(), "set_alias", "big rat");
    call_other(this_object(), "set_level", 3);
    call_other(this_object(), "set_short", "A big rat carrying a rotten piece of meat in its mouth");
    call_other(this_object(), "set_long", "This rat is all covered with dirt and it stinks.\n" + 
                                          "You feel sick just as you watch its slimy and hairless tail.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_animal(1);
}

