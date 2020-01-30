inherit "obj/monster";

reset(arg) {
    object money;    
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 29);
    call_other(this_object(), "set_name", "Priest");
    call_other(this_object(), "set_alias", "priest");
    call_other(this_object(), "set_short", "A tall priest, clad in white robes");
    call_other(this_object(), "set_long", "This is a tall man. He is a priest and \n" +
                                          "teaches religious matters to the Dequan knights.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/prrobes");
    move_object(armour, this_object());
    init_command("wear robes");

    weapon = clone_object("/wizards/nalle/area/knstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
}

