inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_undead(1);
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "Wraith");
    call_other(this_object(), "set_alias", "wraith");
    call_other(this_object(), "set_short", "A loathsome wraith");
    call_other(this_object(), "set_long", "This is an undead being of some sort.\n");
    call_other(this_object(), "set_al", -20);
    call_other(this_object(), "set_aggressive", 1);
    set_block_dir("down");

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear armour");

/*Removed the unexisting weapon to get the mob work - Ahma*/
}
