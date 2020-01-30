inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_dex(40);
    set_name("hobbit");
    set_alias("hobbit");
    set_short("A fat Hobbit");
    set_long("A fat hobbit scratches his butt.\n");
    set_al(30);
    set_aggressive(0);
    set_gender(1);
    set_race("halfling");

    if (!chat_str) {
        chat_str = allocate(3);
         chat_str[0] =
          "Hobbit says: Seen my pipe?\n";
        chat_str[1] =
          "Hobbit says: Lovely weather today.\n";
        chat_str[2] =
          "Hobbit says: Dumdidumdum.\n";
    }

    load_chat(15, chat_str);
}
