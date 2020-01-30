inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(5);
    set_name("knight");
    set_alias("strong knight");
    set_short("A Dequan Knight.");
    set_long("This is one of the Dequan Knights that patrol the streets of Chamron. He seems like a skilled warrior, and a worthy opponent.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(1);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The knight swings his fine weapon at an imaginary opponent.\n";
        chat_str[1] =
          "Knight says: Next week I will be promoted to a guardian of the Temple. \n";
        chat_str[2] =
          "Knight says: That Darvox is up to no good. I don't trust his black magic.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Knight says: It is almost unhonorable to fight such a fool! \n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
