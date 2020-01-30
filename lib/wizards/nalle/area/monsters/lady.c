inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(13);
    set_race("human");
    set_gender(2);
    set_name("Lady");
    set_alias("lady");
    set_short("A knight's lady, conversing with another knight");
    set_long("A knight's lady seems to have found a secret friend.\n");
    set_al(-5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The lady peers over the bushes at her male friend, and giggles childlishly.\n";
        chat_str[1] =
          "Lady says: 'Oh, Pablo!'\n";
        chat_str[2] =
          "Lady sighs: 'Oh my darling Pablo, what if Henry finds out?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Lady whines: 'He forced me to do it!'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

}
