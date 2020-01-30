inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_name", "rat");
    call_other(this_object(), "set_alias", "small rat");
    call_other(this_object(), "set_level", 1);
    call_other(this_object(), "set_short", "A small rat running in the darkness");
    call_other(this_object(), "set_long", "This rat is all covered with dirt and it stinks.\n" + 
                                          "It is munching something in its nauseating small mouth.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_animal(1);
}
