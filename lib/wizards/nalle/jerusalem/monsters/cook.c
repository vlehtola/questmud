inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 25);
    call_other(this_object(), "set_name", "Cook");
    call_other(this_object(), "set_alias", "cook");
    call_other(this_object(), "set_short", "A busy cook");
    call_other(this_object(), "set_long", "The cook is preparing some stew in a massive pot.\n");
    call_other(this_object(), "set_al", 1);
    call_other(this_object(), "set_aggressive", 0);

    weapon = clone_object("/wizards/nalle/jerusalem/eq/spoon");
    move_object(weapon, this_object());
    init_command("wield hatchet");
}

