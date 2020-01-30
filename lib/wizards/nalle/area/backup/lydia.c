inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_name("Lydia");
    set_alias("lydia");
    set_short("Lydia, the black robed shopkeeper");
    set_long("Lydia is clothed in beautiful black robes, and seems extremely intelligent\n");
    set_al(-5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Lydia starts writing, a scroll.\n";
        chat_str[1] =
          "Lydia arranges the cans of bat guano on the shelves.\n";
        chat_str[2] =
          "Lydia mutters: I'll have to start summoning customers again... \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Lydia's eyes flash bright red in anger. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
