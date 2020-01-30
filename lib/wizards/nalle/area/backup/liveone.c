inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_name", "Liveone");
    call_other(this_object(), "set_alias", "liveone");
    call_other(this_object(), "set_short", "A failed creation.");
    call_other(this_object(), "set_long", "This is one of Darvox's failed creations, it looks hideous.\n");
    call_other(this_object(), "set_al", -20);
    set_block_dir("east");
    call_other(this_object(), "set_aggressive", 1);

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
