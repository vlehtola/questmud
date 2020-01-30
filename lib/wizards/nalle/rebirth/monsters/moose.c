inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(30);
    set_name("moose");
    set_alias("Moose");
    set_short("A large moose");
    set_long("This moose sure is big. It follows your movements closely\n" +
             "and occasionally shakes its horns meaningfully.\n");
    set_al(1);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] = "The moose eyes you suspiciously.\n";
        chat_str[1] = "The moose chews on some blueberries.\n";
        chat_str[2] = "You step into some moose-droppings. Damn.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The moose rushes at you with its horns.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

