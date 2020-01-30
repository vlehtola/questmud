inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "Mage");
    call_other(this_object(), "set_alias", "mage");
    call_other(this_object(), "set_short", "A red robed mage");
    call_other(this_object(), "set_long", "This is one of Darvox's apprentices. He is\n" +
                                          "wearing red robes and his robes conceal his face.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/magcloak");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/magstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
}

