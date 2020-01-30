inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 4);
    call_other(this_object(), "set_name", "hobbit");
    call_other(this_object(), "set_alias", "chef");
    call_other(this_object(), "set_short", "A hobbit chef making dinner");
    call_other(this_object(), "set_long", "A hobbit chef is prepairing dinner for miners. Hobbit is ugly and looks\n" +
                                          "like he has been prepairing dinners hole his short life. He is too\n" +
                                          "fat to move fast.\n");
    call_other(this_object(), "set_al", 10);
    set_race("hobbit");
    set_gender(1);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
}



