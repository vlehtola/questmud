inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(28);
    set_name("stag");
    set_alias("Stag");
    set_short("A majestic stag");
    set_long("This stag is still completely unaware of you, usually they\n" +
             "keep a good distance to adventurers.\n");
    set_al(1);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "The stag stretches itself warily.\n";
        chat_str[1] = "The stag lies down to get some rest.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The stag kicks at you furiously.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

