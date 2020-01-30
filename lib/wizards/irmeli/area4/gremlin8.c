inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money; 
    ::reset(arg);
    if (arg) { return; }
    set_level(17);
    set_name("gremlin");
    set_alias("lookout");
    set_short("A gremlin lookout");
    set_long("A gremlin is looking out for the strangers. The gremlin is looking with its binoculars towards the woods. The gremlin lookout is looking very strong and healthy.\n");
    set_al(15);
    set_aggressive(0);
        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Lookout looks around with its binoculars.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Lookout sniffs the air.\n";
    }
    load_chat(4, chat_str);
    load_a_chat(2, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(8));
    move_object(money, this_object());
    
}
