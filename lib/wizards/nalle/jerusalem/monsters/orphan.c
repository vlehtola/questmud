inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 18);
    call_other(this_object(), "set_name", "Orphan");
    call_other(this_object(), "set_alias", "orphan");
    call_other(this_object(), "set_short", "An orphan");
    call_other(this_object(), "set_long", "A child inhabiting this facility.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/knife2");
    move_object(weapon, this_object());
    init_command("wield dagger");
}

