inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(25);
    set_name("boar");
    set_alias("Boar");
    set_short("A raging boar");
    set_long("This boar seems very agitated to say the least. Once it\n" +
             "notices you, you won't want to be around.\n");
    set_al(1);
    set_aggressive(random(3)%2);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] = "The boar runs around.\n";
        chat_str[1] = "The boar rages around, crashing around the bushes.\n";
        chat_str[2] = "The boar snorts furiously.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The boar drools uncontrollably as it closes in for the kill.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

