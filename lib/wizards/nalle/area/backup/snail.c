inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(1);
    set_name("Snail");
    set_alias("snail");
    set_short("A little snail");
    set_long("A perfect specimen of the common snail. It's waving its antennas vigorously\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The snail starts eating a leaf.\n";
        chat_str[1] =
          "The snail starts towards a maple tree, at a pathetic speed.\n";
        chat_str[2] =
          "The snail looks up at you in awe. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The snail waves it's antennas at you menacingly. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
