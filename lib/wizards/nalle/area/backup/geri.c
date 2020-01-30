inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(69);
    set_name("Geri");
    set_alias("geri");
    set_short("Geri Haniwell, the Spicegirl");
    set_long("Woowoo Geri hani.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
         if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Geri whispers: Hani!.\n";
        chat_str[1] =
          "Geri blinks bjuutifully.\n";
        chat_str[2] =
          "Geri whispers something into Nalle's ear. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Geri screams: "Yikes, move over!". \n"
;
    }
    load_chat(20, chat_str);
    load_a_chat(30, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}

