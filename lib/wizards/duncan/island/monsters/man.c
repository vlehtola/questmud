inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(20);
    set_name("sailor");
    set_short("A thin sailor suffered a shipwreck");
    set_long("A thin sailor has suffered a shipwreck. He survived from the shipwreck,\n"+
             "drived ashore with couple of his mates and started to hate water.\n"+
             "Nowadays he is living in the city, working as an assistant. The\n"+
             "sailor's life is put off behind, it only lives in his memories.\n"+
             "His left arm damaged in the shipwreck.\n");
    set_al(40);
    set_gender(1);
    set_race("human");
    set_aggressive(0);

    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
"Sailor says: 'Damn storm it destroyed the ship and the crew. The ship is wrecked! I can't believe it.'\n";
        chat_str[1] =
"Sailor starts walking around, whistling some familiar tune.\n";
        chat_str[2] =
"Sailor says: 'I remember once, when this great wind was blowing and the sails were set.... Oh well, I must go to work now!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Sailor says: 'I have everything, even the water!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   }









