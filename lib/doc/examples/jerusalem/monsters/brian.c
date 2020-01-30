inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 28);
    call_other(this_object(), "set_name", "brian");
    call_other(this_object(), "set_alias", "Brian");
    call_other(this_object(), "set_short", "Brian, a young fellow clad in white");
    call_other(this_object(), "set_long", "This is Brian, a young bearded man clad in white cloths.\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/jdagger");
    move_object(weapon, this_object());
    init_command("wield dagger");
}
