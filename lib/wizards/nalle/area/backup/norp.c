inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "Norp");
    call_other(this_object(), "set_alias", "norp");
    call_other(this_object(), "set_short", "Norp Alemouth the Barkeeper");
    call_other(this_object(), "set_long", "This is a Norp Alemouth, the barkeeper in \n" +
                                          "the Inn of the Three Bears. He is constantly smiling happily\n" +
                                          "and takes sips of ale every now and then.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/norparmour");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/staff");
    move_object(weapon, this_object());
    init_command("wield staff");
}
