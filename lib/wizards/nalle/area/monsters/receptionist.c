inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(12);
    set_gender(2);
    set_race("human");
    set_name("The receptionist");
    set_alias("receptionist");
    set_short("A receptionist is leaning against the desk.");
    set_long("The receptionist is a young woman. She seems a bit flegmatic.\n");
    set_al(5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The receptionist says: 'You either stay or leave. No in betweens.'\n";
        chat_str[1] =
          "The receptionist grunts at you and dozes off.\n";
        chat_str[2] =
          "The receptionist mutters: 'Don't you try anything, I'm used to handle troublemakers.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The receptionist attempts to grab you by your back and throw you out, but you manage to struggle free. \n"
;
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

}
