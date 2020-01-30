inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_name", "rat");
    call_other(this_object(), "set_alias", "huge rat");
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_short", "A HUGE and evil rat");
    call_other(this_object(), "set_long", "This rat is the biggest you have ever seen, about 2 meters long.\n" + 
                                          "Its eyes are red and gleam in the darkness.\n");
    call_other(this_object(), "set_al", -50);
    call_other(this_object(), "set_aggressive", 1);
    set_block_dir("west");
    set_animal(1);
}

