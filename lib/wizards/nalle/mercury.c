inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(50);
    set_experience(404);
    set_gender(1);
    set_race("human");
    set_name("Stage One - Space manoeuvres");
    set_alias("mind");
    set_short("Stage One - Space manoeuvres");
    set_long("Way out to the west, there's a mindcircus.\n");
    set_al(7);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Geri whispers: Hani!\n";
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

