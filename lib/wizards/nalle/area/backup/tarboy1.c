inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(6);
    set_name("Boy");
    set_alias("boy");
    set_short("A young boy is sitting by the table");
    set_long("This is a young boy, with used and torn clothes.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The boy looks at you suspiciously.\n";
        chat_str[1] =
          "Something bright flashes in the boy's pocket. \n";
        chat_str[2] =
          "The boy says: Get out of my house. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The boy grins and says: My mates will finish you off if I don't. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
