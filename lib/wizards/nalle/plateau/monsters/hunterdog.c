inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(21);
    set_name("dog");
    set_alias("Dog");
    set_short("An old dog");
    set_long("This dog seems to be well, despite its old age. It has\n"+
             " rich gray fur and seems to be happy resting by its doghouse.\n");
    set_al(1);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "The dog barks at you.\n";
        chat_str[1] = "The dog sniffs at you suspiciously.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
 a_chat_str[0] = "The dog growls and barks furiously.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

