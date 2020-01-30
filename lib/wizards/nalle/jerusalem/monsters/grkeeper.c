
inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "groundskeeper");
    call_other(this_object(), "set_alias", "grounds keeper");
    call_other(this_object(), "set_short", "The groundskeeper of the orphanage");
    call_other(this_object(), "set_long", "A middle-aged man sitting on his chair idly.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/baton");
    move_object(weapon, this_object());
    init_command("wield baton");
}

