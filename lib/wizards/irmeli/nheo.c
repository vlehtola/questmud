inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(35);
    set_race("human");
    set_gender(1);
    set_name("nheo");
    set_short("Nheo, the weapons responsible");
    set_long("Nheo is a middle aged man, his duty is to keep an eye on the equipment,\n"+
             "which are trusted to him. He looks quite protective, what comes to his\n"+
             "equipment. He would kill himself if he would lost the equipment, which\n"+
             "are trusted to him.\n");
    set_al(50);

        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Nheo screams: 'Don't you touch my weapons!'\n";
        chat_str[1] =
          "Nheo growls: 'This axe would chop a tree in one blow.'\n";
        chat_str[2] =
          "Nheo looks at the weapons fondly.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Nheo swings his axe in a mad fury.\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);

    weapon = clone_object("/wizards/nalle/area/eq/nheoaxe.c");
    move_object(weapon, this_object());
    init_command("wield axe");
}
