inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(18);
    set_name("man");
    set_alias("human");
    set_short("A man standing next to the well");
    set_long("A man is standing next to the well. He is looking in the well. He is\n"+
             "not very tall or muscular, just a usual-looking man among the human\n"+
             "race. He looks scared.\n");
    set_al(20);
    set_gender(1);
    set_race("human");
    set_aggressive(0);

    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Man says: 'There's something evil in the well.'\n";
        chat_str[1] =
"Man says: 'Dungeon!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Man says: 'Please let me go!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   }









