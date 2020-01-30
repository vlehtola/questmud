inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 40);
    call_other(this_object(), "set_name", "merth");
    call_other(this_object(), "set_alias", "master");
    call_other(this_object(), "set_short", "Merth, the master of the tower");
    call_other(this_object(), "set_long", "Vengeance fills this mans eyes his eyes.\n");
    call_other(this_object(), "set_al", -5);
    call_other(this_object(), "set_aggressive", 1);
    
    weapon = clone_object("/wizards/nalle/jerusalem/eq/masstar.c");
    move_object(weapon, this_object());
    init_command("wield morningstar");
}

