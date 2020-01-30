inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_gender(1);
    set_race("cromagnon");
    set_level(19);
    set_name("Diith");
    set_alias("diith");
    set_short("Diith the fearless barbarian");
    set_long("Diith is without question extremely strong and stupid.\n");
    set_al(-5);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Diith bangs his head against the wall, making pieces of rock to fly.\n";
        chat_str[1] =
          "The barbarian smashes the floor with his fist.\n";
        chat_str[2] =
          "Diith looks at you hungrily and slobbers.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Diith relentlessly pounds your head with his fist. \n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);
}
