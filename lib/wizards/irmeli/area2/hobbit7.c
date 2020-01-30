inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 12);
    call_other(this_object(), "set_name", "hobbit");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A hobbit guard");
    call_other(this_object(), "set_long", "A hobbit guard is guarding the way to the king of hobbits. You can feel\n" +
                                          "that this hobbit guard is big enought to crush you. He is loyal\n" +
                                          "guard of king.\n");
    call_other(this_object(), "set_al", 10);
    set_race("hobbit");
    set_gender(1);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("south");
    
}



