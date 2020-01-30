inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_name", "knight");
    call_other(this_object(), "set_alias", "dequan");
    call_other(this_object(), "set_short", "A Dequan Knight, order of the Pine");
    call_other(this_object(), "set_long", "This is a higher ranking Dequan knight. He is\n" +
                                          "wearing a suit of shining armour and wielding a beautiful weapon.\n" +
                                          "The knight also looks like a good fighter.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/knarmour");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/morningstar");
    move_object(weapon, this_object());
    init_command("wield morningstar");
}
