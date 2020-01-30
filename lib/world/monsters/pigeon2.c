inherit "obj/monster";

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(1);
    set_dex(20);
    set_name("pigeon");
    set_alias("pigeon");
    set_short("A white pigeon");
    set_long("A white pigeon sings lovely songs.\n");
    set_al(0);
    set_aggressive(0);
    set_animal(1);
    
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Pigeon says: Piipiip!\n";
        chat_str[1] =
          "Pigeon says: Piip.\n";
        chat_str[2] =
          "Pigeon says: Cro croo.\n";
    }
    
    load_chat(15, chat_str);
}
