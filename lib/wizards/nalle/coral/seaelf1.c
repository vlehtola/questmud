inherit "obj/monster";

reset(arg) {
    object money;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 10);
    call_other(this_object(), "set_name", "elf");
    call_other(this_object(), "set_alias", "child");
    call_other(this_object(), "set_short", "A sea elf child");
    call_other(this_object(), "set_long", "This is a young sea elf child.\n" +
                                          "He is playing with seashiells.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+1);
    move_object(money, this_object());

    weapon = clone_object("/wizards/nalle/area/club");
    move_object(weapon, this_object());
    init_command("wield club");
}

