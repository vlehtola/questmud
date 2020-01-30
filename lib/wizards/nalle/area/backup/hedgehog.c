inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(2);
    set_name("Hedgehog");
    set_alias("hedgehog");
    set_short("A small hedgehog");
    set_long("This is a cute little hedgehog, looking for food\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The hedgehog nibbles at a plant.\n";
        chat_str[1] =
          "The hedgehog snuffles at your feet.\n";
        chat_str[2] =
          "The hedgehog seems to grimace and pthooeys out a piece of a dandylion. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The hadgehog tries to run away but trips over a small root. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
