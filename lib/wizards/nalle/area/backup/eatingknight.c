inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(14);
    set_name("Knight");
    set_alias("knight");
    set_short("A low order knight eating soup");
    set_long("A young man, eating all he can after a hard training session.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The knight gulps some beer.\n";
        chat_str[1] =
          "Knight says: Oh if that Trebor would only cook better.\n";
        chat_str[2] =
          "The knight eats the soup with an amazing speed. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The Knight belches as he throws a cauldron at you. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

  weapon = clone_object("/wizards/nalle/area/knsword");
    move_object(weapon, this_object());
    init_command("wield sword");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
