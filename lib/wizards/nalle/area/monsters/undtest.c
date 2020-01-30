inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 14);
    set_undead(1);
    call_other(this_object(), "set_name", "Spectre");
    call_other(this_object(), "set_alias", "spectre");
    call_other(this_object(), "set_short", "A hovering spectre");
    call_other(this_object(), "set_long", "A transparent, slightly glowing undead being.\n");
    call_other(this_object(), "set_al", -20);
    call_other(this_object(), "set_aggressive", 1);

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear armour");
}
