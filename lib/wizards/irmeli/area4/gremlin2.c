inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money; 
    ::reset(arg);
    if (arg) { return; }
    set_level(11);
    set_name("gremlin");
    set_alias("keeper");
    set_short("The dungeon keeper gremlin");
    set_long("The dungeon keeper gremlin is guarding here the cages of the mighty thiefs, rapers and killers. This gremlin is two times powerful and meaner as the regular ones. There is a big bunch of keys on it's belt.\n");
    set_al(-11);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Keeper says: 'You are not allowed to be here.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Keeper kicks you.\n";
    }
    load_chat(4, chat_str);
    load_a_chat(2, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(4));
    move_object(money, this_object());
    
}

