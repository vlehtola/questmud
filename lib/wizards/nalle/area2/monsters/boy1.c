inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money,weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(17);
    set_name("boy");
    set_alias("Boy");
    set_short("A boy, standing behind the desk");
    set_long("A boy is taking care of the accounts behind the desk.\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The boy searches for a functional pen.\n";
        chat_str[1] =
          "The boy says: If you want to see the rooms before you check in go north and up.\n";
        chat_str[2] =
          "The boy mumbles something about fractions. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The boy screeches: Security!\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    weapon = clone_object("/wizards/nalle/area/eq/knstaff");
    move_object(weapon, this_object());
    init_command("wield staff");

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}

