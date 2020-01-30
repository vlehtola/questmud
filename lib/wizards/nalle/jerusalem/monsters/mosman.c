inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "man");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "A Moslem man, spending time");
    call_other(this_object(), "set_long", "A Moslem man talking to his acquaintances.\n");
    call_other(this_object(), "set_al", 1);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/knife");
    move_object(weapon, this_object());
    init_command("wield dagger");
}
