inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 10);
    call_other(this_object(), "set_name", "wolf");
    call_other(this_object(), "set_alias", "wolf");
    call_other(this_object(), "set_short", "A wolf, howling to the moon");
    call_other(this_object(), "set_long", "The wolf starts growling at you as you approche it.\n" +
                                          "It doesn't appear to like you.\n");
    call_other(this_object(), "set_wc", 3);
    call_other(this_object(), "set_ac", 0);
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);

}
