inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 17);
    call_other(this_object(), "set_name", "norman");
    call_other(this_object(), "set_alias", "Norman");
    call_other(this_object(), "set_short", "Norman the lousy adventurer");
    call_other(this_object(), "set_long", "Norman was once an adventurer. He\n" +
                                          "was caught shooting the king's deer and sent here.\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/rags");
    move_object(armour, this_object());
    init_command("wear rags");

    weapon = clone_object("/wizards/nalle/area/club");
    move_object(weapon, this_object());
    init_command("wield club");
}
