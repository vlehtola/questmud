inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 19);
    call_other(this_object(), "set_name", "knight");
    call_other(this_object(), "set_alias", "dequan");
    call_other(this_object(), "set_short", "A meditating young knight");
    call_other(this_object(), "set_long", "This knight seems to be in deep thought. It must\n" +
                                          "be some religious study. He wears the emblem of the Pine.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/knarmour");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/knstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
}

