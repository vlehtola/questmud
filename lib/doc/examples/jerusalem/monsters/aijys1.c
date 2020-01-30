inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_race("human");
    set_gender(1);
    set_name("man");
    set_alias("Man");
    set_short("A young man");
    set_long("A young man, looking quite depressed, sitting in the corner.\n");
    set_al(0);
    set_log();
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "The young man sighs 'Why did that animal have to take her?'\n";
        chat_str[1] =
          "The young man sobs 'I had such good plans for us!'\n";
        chat_str[2] =
          "The young man sighs 'If I only were strong enough to beat those guards.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The young man 'You shall feel my wrath then!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(10, a_chat_str);
}






