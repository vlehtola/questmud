inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(3);
    set_name("Moose");
    set_alias("moose");
    set_short("A moose");
    set_long("This is a large moose. It is looking at you flegmatically\n");
    set_al(0);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The moose munches on some leaves.\n";
        chat_str[1] =
          "The moose goes "mrh" at you.\n";
        chat_str[2] =
          "The moose starts munching on a blueberry bush. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The moose shakes it's horns at you. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
