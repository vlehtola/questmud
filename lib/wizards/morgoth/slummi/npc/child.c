inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 1);
    call_other(this_object(), "set_name", "child");
    call_other(this_object(), "set_alias", "boy");
    call_other(this_object(), "set_short", "A street child");
    call_other(this_object(), "set_long",
    "This poor child is here searching some food from trashcans.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_race", "human");
    call_other(this_object(), "set_aggressive", 0);
}
