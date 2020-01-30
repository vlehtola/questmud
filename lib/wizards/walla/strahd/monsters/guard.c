inherit "obj/monster"; 
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_hp", 10000);
    call_other(this_object(), "set_ep", 10000);
    call_other(this_object(), "set_sp", 10000);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "orc");
    call_other(this_object(), "set_short", "A sleepy guard sobbing alone in the dark");
    call_other(this_object(), "set_long", "This grubby orchish guard seems not very happy, since\n" +
                                          "he was not invited to the great feast at the castle,\n" +
                                          "which takes place every now and then.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_spell_chance(21, "exs zzt arr");
    set_skill("cast essence", 21);
    set_skill("cast acid", 21);
    set_skill("cast arrow", 21);
    set_skill("mana control", 69);
    set_skill("chanting", 21);
    set_skill("quick spelling", 100);
    set_skill("quick chant", 100);
    set_skill("mastery of electricity", 100);
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    weapon = clone_object("/wizards/walla/strahd/weapons/axe");
    move_object(weapon, this_object());
    init_command("wield axe");
 
    armour = clone_object("/wizards/walla/strahd/armour/leggarit");
    move_object(armour, this_object());
    init_command("wear leggings");
}
