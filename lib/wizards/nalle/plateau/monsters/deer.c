inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_animal();
    set_gender(0);
    set_level(25);
    set_name("deer");
    set_alias("Deer");
    set_short("An elegant deer");
    set_long("The deer seems to keep a safe distance to you, but nevertheless be\n" +
             "aware that it will defend itself vigilantly should it need to do so.\n");
    set_al(1);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "The deer starts nibbling on some raspberries.\n";
        chat_str[1] = "The deer stands still and observes your movements with interest.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The deer tries to kick at you, but fails.\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}

