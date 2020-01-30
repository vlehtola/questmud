inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 24);
    call_other(this_object(), "set_name", "knight");
    call_other(this_object(), "set_alias", "Knight");
    call_other(this_object(), "set_short", "A knight supervising the training");
    call_other(this_object(), "set_long", "This knight is of higher rank than the others.\n" +
                                          "He has been ordered to supervise the training.\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);


    weapon = clone_object("/wizards/nalle/area/eq/trsword");
    move_object(weapon, this_object());
    init_command("wield sword");
}

