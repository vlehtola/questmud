inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_alias("fisherman");
    set_short("A poor looking fisherman clearing the nets");
    set_long("A poor looking fisherman is clearing the nets here. He's thin, long and\n"+ 
             "dirty. He has lost his left hand to a shark. He has thick and grey bread.\n"+ 
             "He stinks really awful, mix of old fish and salty sea-water.\n");
    
    set_al(20);
    set_gender(1);
    set_race("human");
    set_aggressive(0);

    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
"Fisherman says: 'I had ten nets out last night and got only two small perches.'\n";
        chat_str[1] =
"Fisherman starts clearing the net.\n";
        chat_str[2] =
"Fisherman curses: 'I hate sharks!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Fisherman says: 'I'll feed you to the sharks!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   }









