inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "Fisherman");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "An old fisherman");
    call_other(this_object(), "set_long", "A bearded fisherman, fishing.\n");
    call_other(this_object(), "set_al", 5);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/knife");
    move_object(weapon, this_object());
    init_command("wield dagger");
}
