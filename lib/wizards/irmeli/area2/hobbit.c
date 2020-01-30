inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(3);
    set_name("hobbit");
    set_alias("hobbit");
    set_short("A tiny hobbit");
    set_long("A tiny hobbit is so small that you might crush her by stepping on her. She's crying because she's alone.\n");
    set_race("hobbit");
    set_gender(2);
    set_al(10);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Hobbit bursts into tears.\n";
        chat_str[1] =
          "Hobbit says: 'I have lost my mother.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Hobbit says: 'No no don't kill me.'\n";
    }
    load_chat(1, chat_str);
    load_a_chat(1, a_chat_str);

    
}

