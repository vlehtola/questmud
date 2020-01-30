inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 1);
    call_other(this_object(), "set_name", "ant");
    call_other(this_object(), "set_alias", "worker");
    call_other(this_object(), "set_short", "A black giant ant worker");
    call_other(this_object(), "set_long", "The ant is huge compared to its smaller relatives. It is atleast\n" +
                                          "one and a half meters long and one meter high. It is digging the\n" +
                                          "wall and your presence doesn't seem to distracting it in its work.\n");
    call_other(this_object(), "set_wc", 3);
    call_other(this_object(), "set_ac", 0);
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_animal(1);
    
}
