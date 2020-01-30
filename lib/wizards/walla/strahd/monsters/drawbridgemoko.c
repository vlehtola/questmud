inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 24);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A guard guarding the drawbridge");
    call_other(this_object(), "set_long", "The guard has for job to guard this unholy place.\n" +
                                          "As you look him over he starts to chant in some strange\n" +
                                          "and old-fashioned language.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("north");
    set_spell_chance(69, "exs ssh arr");
    set_skill("cast essence", 69);
    set_skill("cast acid", 69);
    set_skill("cast arrow", 69);
    set_skill("mana control", 21);
    set_skill("chanting", 69);
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    weapon = clone_object("/wizards/walla/strahd/weapons/gsword");
    move_object(weapon, this_object());
    init_command("wield sword");

    armour = clone_object("/wizards/walla/strahd/armour/gboots");
    move_object(armour, this_object());
    init_command("wear boots");
}

