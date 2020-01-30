inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 23);
    call_other(this_object(), "set_name", "Teacher");
    call_other(this_object(), "set_alias", "teacher");
    call_other(this_object(), "set_short", "A toothless teacher");
    call_other(this_object(), "set_long", "The teacher is completely bald and seems old.\n");
    call_other(this_object(), "set_al", 1);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/cane");
    move_object(weapon, this_object());
    init_command("wield cane");
}

