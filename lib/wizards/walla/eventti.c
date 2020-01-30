inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_hp(100);
    set_name("monster");
    set_alias("monster");
    set_short("Walla's Eventmonster");
    set_long("This is Walla's own event monster.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(1);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Monster says: Gloory gloory halleluuja.\n";
        chat_str[1] =
          "Monster says: Thou shalt praise Walla. \n";
        chat_str[2] =
          "Monster says: Walla is BEST!\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Monster says: Hey, get those bloody hands of me! \n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
