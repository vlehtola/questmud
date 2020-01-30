inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(1);
    set_experience(21);
    set_gender(2);
    set_race("human");
    set_name("Geri");
    set_alias("geri");
    set_short("Geri Haniwell, the Spice Girl");
    set_long("Geri is smiling beautifully she is Nalle's hjani.\n");
    set_al(7);
    set_max_hp(query_hp() + 15000);
    set_hp(query_max_hp());

    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Geri whispers: 'Move over!'\n";
        chat_str[1] ="Geri hums a little tune, you feel your exprate dropping.\n";
        chat_str[2] ="Geri sighs: 'Nalle knows how to zigazig-ah!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Geri screams: 'Yikes, move over!'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);

}

