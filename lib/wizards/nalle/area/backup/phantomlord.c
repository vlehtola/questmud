inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon,weapon2;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 66);
    call_other(this_object(), "set_name", "Lord");
    call_other(this_object(), "set_alias", "lord");
    call_other(this_object(), "set_short", "The Phantom Lord");
    call_other(this_object(), "set_long", "With his sword in his hand, to control the land, \n" +
                                          "crushing metal strikes, on this frightening night, fall onto your\n" +
                                          "knees, for the Phantom Lord.\n");
    call_other(this_object(), "set_al", -10);
    set_spell_chance(60, "exs brr blt");
    call_other(this_object(), "set_aggressive", 1);
    set_skill("cast essence", 90);
    set_skill("cast ice", 90);
    set_skill("cast bolt", 90);
    set_skill("mana control", 50);
    set_skill("chanting", 50);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/wizards/nalle/area/pharmour");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/phaxe");
    move_object(weapon, this_object());
    init_command("wield axe");

    weapon2 = clone_object("/wizards/nalle/area/phsword");
    move_object(weapon2, this_object());
    init_command("lwield sword");
}
