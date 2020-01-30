inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(7);
    set_name("hobbit");
    set_alias("dynamiter");
    set_short("A hobbit dynamiter");
    set_long("A hobbit dynamiter expert is highly trained on his job. He has lost his right arm in mine disaster.\n");
    set_race("hobbit");
    set_gender(1);
    set_al(10);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "A stick of dynamite EXPLODES next to you.\n";
        chat_str[1] =
          "Hobbit expert says: 'You need to be careful in this job.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Hobbit expert says: 'I lost my right arm in big explonation.'\n";
    }
    load_chat(1, chat_str);
    load_a_chat(1, a_chat_str);

}

