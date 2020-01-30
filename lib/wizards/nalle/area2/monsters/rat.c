inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(6);
    set_name("Rat");
    set_alias("rat");
    set_short("A pestilent rat");
    set_long("A dirty rat, ridden with fleas, observes you with bulging deformed eyes.\n");
    set_al(-2);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The rat runs into the shadows.\n";
        chat_str[1] =
          "The rat starts nibbling on the limb of a dead leper.\n";
        chat_str[2] =
          "The smell of decomposing corpses makes you nauseous.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The rat waves its tail in anger.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}

