inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {

    int i;
    string str;
    ::reset(arg);
    if(arg) { return; 
}
    set_level(60+random(5));
    set_name("policeman");
    set_alias("human");
    set_race("human");
    move_object(clone_object("wizards/devil/area2/eq/pamppu"),this_object());
    set_short("A policeman");
    set_long("Standing well over 6 feet tall, this huge man bears the crested insignia of\n"+
    "the local police force. Clothed in a dark blue jacket and matching trousers,\n"+
    "he patrols with his truncheon at his side, his handcuffs in his belt and a\n"+
    "whistle in his mouth. His head turns; his eyes peering as he checks you up\n"+
    "and down.\n");

    set_move_at_random(6);
    set_gender(1);
    init_command("wield bludgeon");
 

        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Policeman eyes at you suspiciously.\n";
        chat_str[1] = "Policeman screams: 'Move!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Policeman swings his nightstick around his head and screams.\n";
    }
    load_chat(5, chat_str);
    load_a_chat(5, a_chat_str);
}
