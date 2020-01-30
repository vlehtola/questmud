inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 30);
    call_other(this_object(), "set_name", "Guard");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A stern-looking guard");
    call_other(this_object(), "set_long", "A man ready to take care of blasphemers.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/scimitar");
    move_object(weapon, this_object());
    init_command("wield scimitar");
}

