inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon,armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_name("bandit");
    set_alias("bandit");
    set_short("A bandit.");
    set_long("A fearless bandit, clad in a black cape.\n");
    set_al(-10);
    set_aggressive(1);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The bandit makes hostile gestures with his scimitar to you..\n";
        chat_str[1] =
          "These bandits are not going to leave you pass unharmed.\n";
        chat_str[2] =
          "The bandit moves around you in circles.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The bandit slashes at your face, but you dodge nimbly. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    armour = clone_object("/wizards/nalle/area2/eq/cape");
    move_object(armour, this_object());
    init_command("wear cape");

    weapon = clone_object("/wizards/nalle/area2/eq/scimitar");
    move_object(weapon, this_object());
    init_command("wield scimitar");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
