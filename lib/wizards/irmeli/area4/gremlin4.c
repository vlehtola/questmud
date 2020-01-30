inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money; 
    ::reset(arg);
    if (arg) { return; }
    set_level(13);
    set_name("gremlin");
    set_alias("slaver");
    set_short("A gremlin slaver working on here");
    set_long("A gremlin slaver is cleaning the floors, which are mostly covered with dirt. The slaver looks weak and miserable, but you can't underestimate it's powers. Meaby if it have a good day, it might beat you.\n");
    set_al(10);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Slaver says: 'Please release me from the Chieftain.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Slaver looks like it's going to cry.\n";
    }
    load_chat(4, chat_str);
    load_a_chat(2, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(3));
    move_object(money, this_object());
    
}

