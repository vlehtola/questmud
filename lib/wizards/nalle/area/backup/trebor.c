inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(33);
    set_name("Trebor");
    set_alias("trebor");
    set_short("Trebor, the cook of the fortress");
    set_long("Trebor, the cook seems slightly peculiar, and his cooking is awful.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Trebor whispers: I'm actually the same cook as in under siege.\n";
        chat_str[1] =
          "Trebor juggles 21 knives while chopping bananas.\n";
        chat_str[2] =
          "Trebor says: Don't believe them if they say I once cut my hands off while juggling these knives...\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Trebor says: You think you scare me don't you??? \n";
    }
    load_chat(30, chat_str);
    load_a_chat(30, a_chat_str);

   weapon = clone_object("/wizards/nalle/area/treknife");
    move_object(weapon, this_object());
    init_command("wield knife");

    armour = clone_object("/wizards/nalle/area/trehat");
    move_object(armour, this_object());
    init_command("wear hat");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}

