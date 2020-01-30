inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(24);
    set_name("Elmore");
    set_alias("elmore");
    set_short("Elmore, a member of the local thieves");
    set_long("This is Elmore, one of the thieves of Chamron. He is clad in dark clothes.\n");
    set_al(-10);
    set_aggressive(0);
    set_move_at_random(0);
        set_block_dir("west");
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Elmore grunts: Sorry, mate. You can't see the boss.\n";
        chat_str[1] =
          "Elmore sharpens his dagger.\n";
        chat_str[2] =
          "Elmore says: If you want to become a thief, let us know. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Elmore shouts: Hey, boss there are troublemakers here. \n"
;
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
