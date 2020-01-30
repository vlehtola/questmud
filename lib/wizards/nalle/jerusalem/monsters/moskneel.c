inherit "obj/monster";

reset(arg) {
    object armour;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 22);
    call_other(this_object(), "set_name", "Man");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "A man kneeling on a rug");
    call_other(this_object(), "set_long", "A man kneeling on a rug chanting and praying.\n");
    call_other(this_object(), "set_al", 1);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/knife3");
    move_object(weapon, this_object());
    init_command("wield dagger");
}

