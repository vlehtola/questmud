inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 18);
    call_other(this_object(), "set_name", "Spirit");
    call_other(this_object(), "set_alias", "spirit");
    call_other(this_object(), "set_short", "A spirit guarding the grove");
    call_other(this_object(), "set_long", "This is an undead being of some sort.\n");
    call_other(this_object(), "set_al", -20);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("east");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/rags");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/club");
    move_object(weapon, this_object());
    init_command("wield club");
}
