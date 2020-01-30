inherit "obj/monster";

reset(arg) {
    object money;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 30);
    call_other(this_object(), "set_name", "Darvox");
    call_other(this_object(), "set_alias", "darvox");
    call_other(this_object(), "set_short", "Darvox, the master of the elements");
    call_other(this_object(), "set_long", "This is Darvox, the most dreaded being in the realm,\n" +
                                               "the undisputed leader of the black robed magic users. He is fairly\n" +
                                               "young and tall. The air around him crackles from magical energy.\n");
    call_other(this_object(), "set_al", -6);
    set_spell_chance(60, "exs fla bls");
    call_other(this_object(), "set_aggressive", 1);
    set_skill("cast essence", 99);
    set_skill("cast fire", 99);
    set_skill("mastery of fire", 99);
    set_skill("mastery of elements", 99);
    set_skill("cast blast", 99);
    set_skill("mana control", 99);
    set_skill("chanting", 88);
    set_block_dir("up");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    weapon = clone_object("/wizards/nalle/area/darvdagger");
    move_object(weapon, this_object());
    init_command("wield dagger");
}

