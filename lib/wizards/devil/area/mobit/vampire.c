inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(37);
    set_name("vampire");
    set_alias("vampire");
    set_undead(1);
    set_short("A strange looking vampire");
    set_long("A bloodthirsty vampire looking for a victim to bite.\n"+
                  "This vampire is huge and old. Vampire's canine teeths\n"+
                  "are sharp and covered with blood. When you look at the vampire closer,\n"+
                  "you can notice that this vampire is too close to you and can almost bite you.\n");
    set_al(-100);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Vampire looks at you hungrily.\n";
        chat_str[1] = "Vampire says: I'm hungry.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Vampire roars: Now I'm going to drink your tasty blood!\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
    
}
