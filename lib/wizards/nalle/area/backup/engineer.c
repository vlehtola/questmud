inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_name("Engineer");
    set_alias("engineer");
    set_short("An aging engineer");
    set_long("A bald man, who seems to explain things with an extreme speed.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Engineer mutters: How about if I make it use the thermonuclear vacuum?\n";
        chat_str[1] =
          "The engineer shakes his cane vigorously while explaining his tactics.\n";
        chat_str[2] =
          "You hear a knight whisper: Whoever enrolled these engineers? \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Engineer whines: You don't like my idea? Fine, I'll sell it to an opposing power!\n";
    }
    load_chat(30, chat_str);
    load_a_chat(30, a_chat_str);

   weapon = clone_object("/wizards/nalle/area/cane");
    move_object(weapon, this_object());
    init_command("wield cane");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
