inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(15);
    set_name("George");
    set_alias("george");
    set_short("George of the jungle");
    set_long("George seems to have been found from the wilderness.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "George meeps: The Knights are cutting down all the forests!\n";
        chat_str[1] =
          "George scratches his armpits idly.\n";
        chat_str[2] =
          "George goes: I hope they haven't hurt my puddings... \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "George hits you over the head with his club. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

   weapon = clone_object("/wizards/nalle/area/club");
    move_object(weapon, this_object());
    init_command("wield halberd");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
