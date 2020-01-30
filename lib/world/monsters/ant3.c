inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_name", "ant");
    call_other(this_object(), "set_alias", "soldier");
    call_other(this_object(), "set_level", 5);
    call_other(this_object(), "set_short", "An ant soldier");
    call_other(this_object(), "set_long", "This human sized ant is definitely a soldier. It is seems to be\n" +
                                          "well aware of your presence and is watching you closely.\n" +
                                          "It has big claws, which make you feel uneasy. You shiver from the\n" +
                                          "thought how easily they might tear you apart.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_skills(1, 30);
    set_skills(2, 15);
    set_skills(3, 10);
        set_animal(1);
}
