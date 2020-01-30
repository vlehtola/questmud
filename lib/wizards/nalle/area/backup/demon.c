inherit "obj/monster";

reset(arg) {
    object money;
    object weapon,weapon2;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 33);
    call_other(this_object(), "set_name", "ymiel");
    call_other(this_object(), "set_alias", "demon");
    call_other(this_object(), "set_short", "Ymiel, a guardian demon summoned by Darvox");
    call_other(this_object(), "set_long", "Ymiel is the materialization of your nightmares. \n" +
                                          "It's face is covered by bright red hair, as is the rest of it's body.\n" +
                                          "Only the bright red eyes are visible.\n");
    call_other(this_object(), "set_al", -50);
    set_spell_chance(60, "exs fla blt");
    call_other(this_object(), "set_aggressive", 1);
    set_skill("cast essence", 56);
    set_skill("cast fire", 56);
    set_skill("cast bolt", 56);
    set_skill("mana control", 13);
    set_skill("chanting", 13);
    set_block_dir("up");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    weapon = clone_object("/wizards/nalle/area/demonaxe");
    move_object(weapon, this_object());
    init_command("wield axe");

    weapon2 = clone_object("/wizards/nalle/area/demonaxe");
    move_object(weapon2, this_object());
    init_command("lwield axe");
}

