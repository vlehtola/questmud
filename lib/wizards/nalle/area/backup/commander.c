inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(45);
    set_name("Alfons");
    set_alias("alfons");
    set_short("Alfons, the commander of the Dequan knights");
    set_long("Alfons seems strong, but perhaps not very bright.\n");
    set_al(5);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Alfons says: Now I understand how your supposed to look at this map.\n";
        chat_str[1] =
          "Alfons throws a dart at the dartboard but misses. What a hand.\n";
        chat_str[2] =
          "Alfons draws some lines on a piece of paper, then curses and throws it away.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The commander skillfully slashes at you with his sword.\n";
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

    armour = clone_object("/wizards/nalle/area/eq/comring");
    move_object(armour, this_object());
    init_command("wear ring");

    weapon = clone_object("/wizards/nalle/area/eq/comsword");
    move_object(weapon, this_object());
    init_command("wield sword");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(22));
    move_object(money, this_object());
}

