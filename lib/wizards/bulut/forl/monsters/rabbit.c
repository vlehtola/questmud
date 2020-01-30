inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(1);
    set_dex(10);
    set_name("rabbit");
    set_alias("rabbit");
set_short("A dorrible little rabbit");
set_long("A dorrible little rabbit is eating grass here.\n");
    set_al(20);
    set_aggressive(0);
    set_animal(1);
    set_race("rabbit");
    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Rabbit hops up and down!\n";
    }

    load_chat(15, chat_str);
}
