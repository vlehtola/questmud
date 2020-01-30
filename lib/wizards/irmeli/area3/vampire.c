inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money; 
    ::reset(arg);
    if (arg) { return; }
    set_level(27);
    set_name("vampire");
    set_alias("vampire");
    set_short("A bloodthirst vampire");
    set_long("A bloodthirst vampire looking for victim to bite. This vampire is huge and old. Vampires canine teeths are sharp and covered with blood.\n");
    set_al(10);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Vampire looks at you.\n";
        chat_str[1] =
          "Vampire says: I'm hungry.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Vampire says: Let me bite you.\n";
    }
    load_chat(15, chat_str);
    load_a_chat(5, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(7));
    move_object(money, this_object());
    
}

