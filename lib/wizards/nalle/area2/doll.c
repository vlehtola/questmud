inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(69);
    set_exp(69000000);
    set_name("Mariah");
    set_alias("mariah");
    set_short("Mariah Carey, the honey");
    set_long("This is Mariah Carey. Wow! She sure looks like Nalle's hani.\n");
    set_gender("2");
    set_al(21);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Mariah whispers: Hani!.\n";
        chat_str[1] =
          "Mariah hums a little tune.\n";
        chat_str[2] =
          "Mariah smiles bjuutifully and hugs Nalle. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mariah goes: Yikes!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(21));
    move_object(money, this_object());
}
